import file
import boto3
import time
import os
from threading import Thread, Event
import resource
import signal

# Compress time global
compress_time = 0
read_time = 0
upload_time = 0

# PID = os.getpid()

# Reusable Thread class from: https://www.codeproject.com/Tips/1271787/Python-Reusable-Thread-Class
class ReusableThread(Thread):
    """
    This class provides code for a restartale / reusable thread

    join() will only wait for one (target)functioncall to finish
    finish() will finish the whole thread (after that, it's not restartable anymore)
        
    """

    def __init__(self, target, args):
        self._startSignal = Event()
        self._oneRunFinished = Event()
        self._finishIndicator = False
        self._callable = target
        self._callableArgs = args

        Thread.__init__(self)

    def restart(self):
        """make sure to always call join() before restarting"""
        self._startSignal.set()

    def run(self):
        """ This class will reprocess the object "processObject" forever.
        Through the change of data inside processObject and start signals
        we can reuse the thread's resources"""

        self.restart()
        while(True):    
            # wait until we should process
            self._startSignal.wait()

            self._startSignal.clear()

            if(self._finishIndicator):# check, if we want to stop
                self._oneRunFinished.set()
                return
            
            # call the threaded function
            self._callable(*self._callableArgs)

            # notify about the run's end
            self._oneRunFinished.set()

    def join(self):
        """ This join will only wait for one single run (target functioncall) to be finished"""
        self._oneRunFinished.wait()
        self._oneRunFinished.clear()

    def finish(self):
        self._finishIndicator = True
        self.restart()
        self.join()

def do_nothing(*args):
    pass

# **** PARALLEL EXECUTION WITH REUSABLE THREADS ****
def read_chunk(read_index, chunk_string, read_arg, s3, code_start):
    # Starting to read chunk
    global read_time
    i = read_index[0]
    print("reading chunk " + str(i))
    start = time.time()

    ###
    obj = s3.get_object(Bucket='succinct-datasets', Key=chunk_string + str(i) + ".succinct")
    read_arg[0] = obj['Body'].read().decode('utf-8')
    del obj
    ###

    # write chunk times to file and mark time
    # end = time.time()
    # read_time += end - start
    # read_time_file = open("read_time_file.txt","a")
    # read_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " duration: " + str(end - start) + "\n")

def compress_chunk(compress_index, read_arg, compressed_arg, code_start):
    # Starting to compress chunk
    global compress_time
    i = compress_index[0]
    print("compressing chunk " + str(i))
    start = time.time()

    ###
    q = file.File(0, read_arg[0], 32, 32, 128, 0, 1)
    compressed_arg[0] = q.GetContent().tobytes()
    q.DeleteContent()
    del q
    ###

    # write chunk times to file and mark time
    # end = time.time()
    # compress_time += end - start
    # compress_time_file = open("compress_time_file.txt","a")
    # compress_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " duration: " + str(end - start) + "\n")

def upload_chunk(upload_index, chunk_string, compressed_arg, s3, code_start):
    # Starting to upload chunk
    global upload_time
    i = upload_index[0]
    print("uploading chunk " + str(i))
    start = time.time()

    ###
    s3.put_object(Body=compressed_arg[0], Bucket='succinct-datasets', Key=chunk_string + "compressed-" + str(i) + ".succinct")
    ###

    # write chunk times to file and mark time
    # end = time.time()
    # upload_time += end - start
    # upload_time_file = open("upload_time_file.txt","a")
    # upload_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " duration: " + str(end - start) + "\n")


# # **** PARALLEL EXECUTION WITH LIST OF THREAD FUNCTIONS ****

# def read_chunk(i, chunk_string, read_chunks, s3, code_start):
#     print("reading chunk " + str(i))
#     global read_time
#     start = time.time()
#     obj = s3.get_object(Bucket='succinct-datasets', Key=chunk_string + str(i) + ".succinct")
#     read_chunks.append(obj['Body'].read().decode('utf-8'))
#     del obj
#     end = time.time()
#     read_time += end - start

#     # # write chunk times to file
#     # read_time_file = open("read_time_file.txt","a")
#     # read_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " finish: " + str(end - code_start) + "\n")

# def compress_chunk(i, read_chunks, compressed_chunks, code_start):
#     print("compressing chunk " + str(i))
#     global compress_time
#     start = time.time()
#     q = file.File(0, read_chunks[i], 32, 32, 128, 0, 1)
#     compressed_chunks.append(q.GetContent().tobytes())
#     q.DeleteContent()
#     del q
#     read_chunks[i] = None
#     end = time.time()
#     compress_time += end - start

#     # # write chunk times to file
#     # compress_time_file = open("compress_time_file.txt","a")
#     # compress_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " finish: " + str(end - code_start) + "\n")

# def upload_chunk(i, chunk_string, compressed_chunks, s3, code_start):
#     print("uploading chunk " + str(i))
#     global upload_time
#     start = time.time()
#     s3.put_object(Body=compressed_chunks[i], Bucket='succinct-datasets', Key=chunk_string + "compressed-" + str(i) + ".succinct")
#     compressed_chunks[i] = None
#     end = time.time()
#     upload_time += end - start

    # # write chunk times to file
    # upload_time_file = open("upload_time_file.txt","a")
    # upload_time_file.write("chunk " + str(i) +  " start: " + str(start - code_start) + " finish: " + str(end - code_start) + "\n")

# **** FUNCTION START ****
# compress file
start = time.time()
# Define variables
chunk_string = "sample.txt" + "-chunk-"
s3 = boto3.client("s3", aws_access_key_id="AKIAJS52NT4AB7WQAZKA", 
                aws_secret_access_key="5nc0Bc5HD8ugeqLRfF3h6kR9OCfLfQ/VTRYOaxy/", 
                region_name="us-east-2")
# Depends on number of chunks file is split into
num_chunks = 1167
read_chunks = []
compressed_chunks = []

# COMPRESS WITH FILES
# q = file.File("sample.txt-chunk-1160.succinct", 32, 32, 128, 0, 1)

# COMPRESS IN MEM
# f = open("sample.txt-chunk-1166.succinct","r")
# content = f.read()
# q = file.File(0, content, 32, 32, 128, 0, 1)


# # **** QUERY FOR NUMBER OF CHUNK FILES ****
# s3 = boto3.resource("s3")
# bucket = s3.Bucket('succinct-datasets')
# for bucket_obj in bucket.objects.all():
#     if (chunk_string in str(bucket_obj)):
#         num_chunks += 1
# print("The num chunks is: " + str(num_chunks))

# signal.signal(signal.SIGUSR1, do_nothing)

# **** PARALLEL EXECUTION WITH REUSABLE THREADS ****

read_index = [0]
compress_index = [0]
upload_index = [0]


# Variables to keep track of read and compressed data
read_arg = [0]
compressed_arg = [0]

read_thread = ReusableThread(target = read_chunk, args=(read_index, chunk_string, read_arg, s3, start))
compress_thread = ReusableThread(target = compress_chunk, args=(compress_index, read_arg, compressed_arg, start))
upload_thread = ReusableThread(target = upload_chunk, args=(upload_index, chunk_string, compressed_arg, s3, start))

for i in range(0, num_chunks + 2):
    if (i == 0):
        # START: read
        read_index[0] = i

        read_thread.start()
    elif (i == 1):
        # RESTART: read START: compress
        read_thread.join()

        read_index[0] = i
        compress_index[0] = i - 1

        compress_thread.start()
        read_thread.restart()
    elif (i == 2):
        # RESTART: compress, read START: upload
        read_thread.join()
        compress_thread.join()

        read_index[0] = i
        compress_index[0] = i - 1
        upload_index[0] = i - 2

        upload_thread.start()
        compress_thread.restart()
        read_thread.restart()

    elif (i == num_chunks):
        # RESTART: upload, compress
        read_thread.join()
        compress_thread.join()
        upload_thread.join()

        compress_index [0] = i - 1
        upload_index [0] = i - 2

        upload_thread.restart()
        compress_thread.restart()
    elif (i == num_chunks + 1):
        # RESTART: upload
        compress_thread.join()
        upload_thread.join()

        upload_index [0] = i - 2

        upload_thread.restart()

        # Join last thread and finish all threads
        upload_thread.join()

        read_thread.finish()
        compress_thread.finish()
        upload_thread.finish()
    else:
        # RESTART: upload, compress, read
        read_thread.join()
        compress_thread.join()
        upload_thread.join()

        read_index[0] = i
        compress_index[0] = i - 1
        upload_index[0] = i - 2

        upload_thread.restart()
        compress_thread.restart()
        read_thread.restart()

# # **** PARALLEL EXECUTION WITH LIST OF THREADS ****
# read_threads = []
# compress_threads = []
# upload_threads = []

# for i in range(0, num_chunks + 2):
#     if (i == 0):
#         # Create read thread
#         read_thread = Thread(target=read_chunk, args=(0, chunk_string, read_chunks, s3, start))
#         read_thread.start()
#         read_threads.append(read_thread)
#     elif (i == 1):
#          # Create read thread
#         read_thread = Thread(target=read_chunk, args=(1, chunk_string, read_chunks, s3, start))
#         read_thread.start()
#         read_threads.append(read_thread)

#         # If read_threads[0] isn't done, finish
#         if read_threads[0].is_alive():
#             read_threads[0].join()
#         # Create compress thread
#         compress_thread = Thread(target=compress_chunk, args=(0, read_chunks, compressed_chunks, start))
#         compress_thread.start()
#         compress_threads.append(compress_thread)
#     elif (i == num_chunks):
#         # If read_threads[num_chunks - 1] isn't done, finish
#         if read_threads[i - 1].is_alive():
#             read_threads[i - 1].join()

#         # If compress_threads[num_chunks - 2] isn't done, finish
#         if compress_threads[i - 2].is_alive():
#             compress_threads[i - 2].join()
        
#         # Create compress thread
#         compress_thread = Thread(target=compress_chunk, args=(i - 1, read_chunks, compressed_chunks, start))
#         compress_thread.start()
#         compress_threads.append(compress_thread)
#         # Create upload thread
#         upload_thread = Thread(target=upload_chunk, args=(i - 2, chunk_string, compressed_chunks, s3, start))
#         upload_thread.start()
#         upload_threads.append(upload_thread)
#     elif (i == num_chunks + 1):
#         # If compress_threads[num_chunks - 1] isn't done, finish
#         if compress_threads[i - 2].is_alive():
#             compress_threads[i - 2].join()
#         # Create upload thread
#         upload_thread = Thread(target=upload_chunk, args=(i - 2, chunk_string, compressed_chunks, s3, start))
#         upload_thread.start()
#         upload_threads.append(upload_thread)
#     else:
#         # Create read thread
#         read_thread = Thread(target=read_chunk, args=(i, chunk_string, read_chunks, s3, start))
#         read_thread.start()
#         read_threads.append(read_thread)

#         # If read_threads[i - 1] isn't done, finish
#         if read_threads[i - 1].is_alive():
#             read_threads[i - 1].join()
            
#         # If compress_threads[i - 2] isn't done, finish
#         if compress_threads[i - 2].is_alive():
#             compress_threads[i - 2].join()

#         # Create compress thread
#         compress_thread = Thread(target=compress_chunk, args=(i - 1, read_chunks, compressed_chunks, start))
#         compress_thread.start()
#         compress_threads.append(compress_thread)

#         # Create upload thread
#         upload_thread = Thread(target=upload_chunk, args=(i - 2, chunk_string, compressed_chunks, s3, start))
#         upload_thread.start()
#         upload_threads.append(upload_thread)

# os.kill(PID, signal.SIGUSR1)


# # **** SEQUENTIAL EXECUTION ****
# for i in range(0, num_chunks + 2):
#     if (i == 0):
#         read_chunk(0, chunk_string, read_chunks, s3)
#     elif (i == 1):
#         read_chunk(1, chunk_string, read_chunks, s3)
#         compress_chunk(0, read_chunks, compressed_chunks)
#     elif (i == num_chunks):
#         compress_chunk(num_chunks - 1, read_chunks, compressed_chunks)
#         upload_chunk(num_chunks - 2, chunk_string, compressed_chunks, s3)
#     elif (i == num_chunks + 1):
#         upload_chunk(num_chunks - 1, chunk_string, compressed_chunks, s3)
#     else:
#         read_chunk(i, chunk_string, read_chunks, s3)
#         compress_chunk(i - 1, read_chunks, compressed_chunks)
#         upload_chunk(i - 2, chunk_string, compressed_chunks, s3)


# signal.signal(signal.SIGUSR1, do_nothing)

# #with s3
# for i in range(11,12):
#     obj = s3.get_object(Bucket='succinct-datasets', Key=chunk_string + str(i) + ".succinct")
#     print("read " + str(i))
#     q = file.File(0, obj['Body'].read().decode('utf-8'), 32, 32, 128, 0, 1)
#     compressed_content = q.GetContent().tobytes()
#     print("compressed " + str(i))
#     s3.put_object(Body=compressed_content, Bucket='succinct-datasets', Key=chunk_string + "compressed-" + str(i) + ".succinct")
#     print("uploaded " + str(i))

# # without s3
# for i in range(1660, 1667):
#     f = open(chunk_string + str(i) + ".succinct","r")
#     content = f.read()
#     q = file.File(0, content, 32, 32, 128, 0, 1)
#     text_file = open(chunk_string + str(i) + "-compressed-local.succinct", "wb")
#     text_file.write(q.GetContent().tobytes())

# os.kill(PID, signal.SIGUSR1)
# print("done")

# # **** UPLOAD FILE TO BUCKET ****
# s3 = boto3.resource("s3")
# os.chdir("/tmp")
# f = open("test.txt","w")
# f.write("hello this is a test")
# f.close()
# s3.meta.client.upload_file("/tmp/test.txt", "succinct-datasets", "test.txt")

# # **** COMPRESS BY INPUT ****
# # Get file content from S3 and save as "input"
# s3 = boto3.client("s3")
# obj = s3.get_object(Bucket='succinct-datasets', Key=event['key1'])
# input = obj['Body'].read().decode('utf-8')

# # Compress the input using file module
# q = file.File(0, input, 32, 32, 128, 0, 1)
# content = q.GetContent().tobytes()

# # Upload content back onto S3 in .succinct file
# s3.put_object(Body=content, Bucket='succinct-datasets', Key=event['key1'] + ".succinct")

# # **** COMPRESS BY FILE ****
# s3 = boto3.resource("s3")
# os.chdir("/tmp")
# s3.Bucket('succinct-datasets').download_file(event['key1'], event['key1'])
# q = file.File(event['key1'], 32, 32, 128, 0, 1)

# # **** CALCULATE COMPRESSION RATIO ****
# s3 = boto3.resource("s3", aws_access_key_id="AKIAJS52NT4AB7WQAZKA", 
#                 aws_secret_access_key="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", 
#                 region_name="us-east-2")
# bucket = s3.Bucket('succinct-datasets')
# orignal_sizes = 0
# compressed_sizes = 0
# for i in range (0, num_chunks):
#     orignal_sizes += bucket.Object("sample.txt-chunk-" + str(i) + ".succinct").content_length
#     compressed_sizes += bucket.Object("sample.txt-chunk-compressed-" + str(i) + ".succinct").content_length

# print(orignal_sizes)
# print(compressed_sizes)
# print(orignal_sizes/compressed_sizes)


# # **** REMOVE OBJECTS FROM S3 ****
# s3 = boto3.resource("s3")
# for i in range (0, 200):
#     obj = s3.Object("succinct-datasets", event['key1'] + "-chunk-compressed-" + str(i) +  ".succinct")
#     obj.delete()
#     obj = s3.Object("succinct-datasets", event['key1'] + "-chunk-" + str(i) +  ".succinct")
#     obj.delete()

print("File compression and upload is complete")
print("read time: " + str(read_time))
print("compress time: " + str(compress_time))
print("upload time: " + str(upload_time))
print("TOTAL DURATION: " + str(time.time() - start))
print(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)