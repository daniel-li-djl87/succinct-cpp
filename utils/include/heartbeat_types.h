/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef heartbeat_TYPES_H
#define heartbeat_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




class HeartBeat;

typedef struct _HeartBeat__isset {
  _HeartBeat__isset() : timestamp(false) {}
  bool timestamp :1;
} _HeartBeat__isset;

class HeartBeat {
 public:

  HeartBeat(const HeartBeat&);
  HeartBeat& operator=(const HeartBeat&);
  HeartBeat() : timestamp(0) {
  }

  virtual ~HeartBeat() throw();
  int64_t timestamp;

  _HeartBeat__isset __isset;

  void __set_timestamp(const int64_t val);

  bool operator == (const HeartBeat & rhs) const
  {
    if (!(timestamp == rhs.timestamp))
      return false;
    return true;
  }
  bool operator != (const HeartBeat &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HeartBeat & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(HeartBeat &a, HeartBeat &b);

inline std::ostream& operator<<(std::ostream& out, const HeartBeat& obj)
{
  obj.printTo(out);
  return out;
}



#endif