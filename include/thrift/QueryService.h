/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef QueryService_H
#define QueryService_H

#include <thrift/TDispatchProcessor.h>
#include "thrift/succinct_types.h"



class QueryServiceIf {
 public:
  virtual ~QueryServiceIf() {}
  virtual int32_t init(const int32_t id) = 0;
  virtual void get(std::string& _return, const int64_t key) = 0;
};

class QueryServiceIfFactory {
 public:
  typedef QueryServiceIf Handler;

  virtual ~QueryServiceIfFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QueryServiceIf* /* handler */) = 0;
};

class QueryServiceIfSingletonFactory : virtual public QueryServiceIfFactory {
 public:
  QueryServiceIfSingletonFactory(const boost::shared_ptr<QueryServiceIf>& iface) : iface_(iface) {}
  virtual ~QueryServiceIfSingletonFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QueryServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
};

class QueryServiceNull : virtual public QueryServiceIf {
 public:
  virtual ~QueryServiceNull() {}
  int32_t init(const int32_t /* id */) {
    int32_t _return = 0;
    return _return;
  }
  void get(std::string& /* _return */, const int64_t /* key */) {
    return;
  }
};

typedef struct _QueryService_init_args__isset {
  _QueryService_init_args__isset() : id(false) {}
  bool id;
} _QueryService_init_args__isset;

class QueryService_init_args {
 public:

  QueryService_init_args() : id(0) {
  }

  virtual ~QueryService_init_args() throw() {}

  int32_t id;

  _QueryService_init_args__isset __isset;

  void __set_id(const int32_t val) {
    id = val;
  }

  bool operator == (const QueryService_init_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const QueryService_init_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_init_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_init_pargs {
 public:


  virtual ~QueryService_init_pargs() throw() {}

  const int32_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_init_result__isset {
  _QueryService_init_result__isset() : success(false) {}
  bool success;
} _QueryService_init_result__isset;

class QueryService_init_result {
 public:

  QueryService_init_result() : success(0) {
  }

  virtual ~QueryService_init_result() throw() {}

  int32_t success;

  _QueryService_init_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const QueryService_init_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_init_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_init_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_init_presult__isset {
  _QueryService_init_presult__isset() : success(false) {}
  bool success;
} _QueryService_init_presult__isset;

class QueryService_init_presult {
 public:


  virtual ~QueryService_init_presult() throw() {}

  int32_t* success;

  _QueryService_init_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_get_args__isset {
  _QueryService_get_args__isset() : key(false) {}
  bool key;
} _QueryService_get_args__isset;

class QueryService_get_args {
 public:

  QueryService_get_args() : key(0) {
  }

  virtual ~QueryService_get_args() throw() {}

  int64_t key;

  _QueryService_get_args__isset __isset;

  void __set_key(const int64_t val) {
    key = val;
  }

  bool operator == (const QueryService_get_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const QueryService_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_get_pargs {
 public:


  virtual ~QueryService_get_pargs() throw() {}

  const int64_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_get_result__isset {
  _QueryService_get_result__isset() : success(false) {}
  bool success;
} _QueryService_get_result__isset;

class QueryService_get_result {
 public:

  QueryService_get_result() : success() {
  }

  virtual ~QueryService_get_result() throw() {}

  std::string success;

  _QueryService_get_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const QueryService_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_get_presult__isset {
  _QueryService_get_presult__isset() : success(false) {}
  bool success;
} _QueryService_get_presult__isset;

class QueryService_get_presult {
 public:


  virtual ~QueryService_get_presult() throw() {}

  std::string* success;

  _QueryService_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class QueryServiceClient : virtual public QueryServiceIf {
 public:
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t init(const int32_t id);
  void send_init(const int32_t id);
  int32_t recv_init();
  void get(std::string& _return, const int64_t key);
  void send_get(const int64_t key);
  void recv_get(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QueryServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QueryServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_init(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QueryServiceProcessor(boost::shared_ptr<QueryServiceIf> iface) :
    iface_(iface) {
    processMap_["init"] = &QueryServiceProcessor::process_init;
    processMap_["get"] = &QueryServiceProcessor::process_get;
  }

  virtual ~QueryServiceProcessor() {}
};

class QueryServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QueryServiceProcessorFactory(const ::boost::shared_ptr< QueryServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< QueryServiceIfFactory > handlerFactory_;
};

class QueryServiceMultiface : virtual public QueryServiceIf {
 public:
  QueryServiceMultiface(std::vector<boost::shared_ptr<QueryServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QueryServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<QueryServiceIf> > ifaces_;
  QueryServiceMultiface() {}
  void add(boost::shared_ptr<QueryServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t init(const int32_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->init(id);
    }
    return ifaces_[i]->init(id);
  }

  void get(std::string& _return, const int64_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(_return, key);
    }
    ifaces_[i]->get(_return, key);
    return;
  }

};



#endif
