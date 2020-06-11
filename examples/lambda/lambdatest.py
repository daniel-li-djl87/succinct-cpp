import file
import kvstore
import semistructuredstore
import os
from os import path
import boto3
import tempfile

# Change the filenames to succinctdi_sa, succinctdir_isa .... and upload to s3
def uploadDirectory(path,bucketname, name):
    s3 = boto3.client("s3")
    for root,dirs,files in os.walk(path):   
        for f in files:
            s3.upload_file(os.path.join(root,f), bucketname, f) 

# compress file
def call_compress (event, context):
    # # Upload a file to the bucket
    # s3 = boto3.resource("s3")
    # os.chdir("/tmp")
    # f = open("test.txt","w")
    # f.write("hello this is a test")
    # f.close()
    # s3.meta.client.upload_file("/tmp/test.txt", "succinct-datasets", "test.txt")

    # Download a file from a bucket and compress
    s3 = boto3.client("s3")
    s3.download_file("succinct-datasets",event['key1'], "/tmp/" + event['key1'])
    os.chdir("/tmp")
    
    # with open(event['key1'], 'r') as f:
        # print(f.read())
 
    q = file.File(event['key1'], 32, 32, 128, 0, 1)

    # for f in os.listdir("/tmp"):
        # print(f)

    uploadDirectory("/tmp/" + event['key1'] + ".succinct", "succinct-datasets", event['key1'])
    
    # out = os.path.isfile("/tmp/" + event['key1'] + ".succinct")
    # print(out)
    
    # Remove compressed .succinct file contents from s3
    # s3 = boto3.resource("s3")
    # obj = s3.Object("succinct-datasets", event['key1'] + ".succinct.metadata")
    # obj.delete()
    print("File compression and upload is complete")

def call_query (event, context):
    # Download .succinct file from bucket and compress
    s3 = boto3.client("s3")
    os.chdir("/tmp")
    os.mkdir(event['key1'])
    s3.download_file("succinct-datasets", event['key1'] + ".metadata", "/tmp/" + event['key1'] + "/" + event['key1']  + ".metadata")
    # for f in os.listdir("/tmp"):
    #     print(f)
    q = file.File(event['key1'])
    print("File deserialization and querying is complete")