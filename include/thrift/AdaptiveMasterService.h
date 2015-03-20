/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef AdaptiveMasterService_H
#define AdaptiveMasterService_H

#include <thrift/TDispatchProcessor.h>
#include "thrift/adaptive_types.h"



class AdaptiveMasterServiceIf {
 public:
  virtual ~AdaptiveMasterServiceIf() {}
  virtual void get_client(std::string& _return) = 0;
  virtual int32_t get_client_id() = 0;
};

class AdaptiveMasterServiceIfFactory {
 public:
  typedef AdaptiveMasterServiceIf Handler;

  virtual ~AdaptiveMasterServiceIfFactory() {}

  virtual AdaptiveMasterServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(AdaptiveMasterServiceIf* /* handler */) = 0;
};

class AdaptiveMasterServiceIfSingletonFactory : virtual public AdaptiveMasterServiceIfFactory {
 public:
  AdaptiveMasterServiceIfSingletonFactory(const boost::shared_ptr<AdaptiveMasterServiceIf>& iface) : iface_(iface) {}
  virtual ~AdaptiveMasterServiceIfSingletonFactory() {}

  virtual AdaptiveMasterServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(AdaptiveMasterServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<AdaptiveMasterServiceIf> iface_;
};

class AdaptiveMasterServiceNull : virtual public AdaptiveMasterServiceIf {
 public:
  virtual ~AdaptiveMasterServiceNull() {}
  void get_client(std::string& /* _return */) {
    return;
  }
  int32_t get_client_id() {
    int32_t _return = 0;
    return _return;
  }
};


class AdaptiveMasterService_get_client_args {
 public:

  AdaptiveMasterService_get_client_args() {
  }

  virtual ~AdaptiveMasterService_get_client_args() throw() {}


  bool operator == (const AdaptiveMasterService_get_client_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AdaptiveMasterService_get_client_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdaptiveMasterService_get_client_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AdaptiveMasterService_get_client_pargs {
 public:


  virtual ~AdaptiveMasterService_get_client_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AdaptiveMasterService_get_client_result__isset {
  _AdaptiveMasterService_get_client_result__isset() : success(false) {}
  bool success;
} _AdaptiveMasterService_get_client_result__isset;

class AdaptiveMasterService_get_client_result {
 public:

  AdaptiveMasterService_get_client_result() : success() {
  }

  virtual ~AdaptiveMasterService_get_client_result() throw() {}

  std::string success;

  _AdaptiveMasterService_get_client_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const AdaptiveMasterService_get_client_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AdaptiveMasterService_get_client_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdaptiveMasterService_get_client_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AdaptiveMasterService_get_client_presult__isset {
  _AdaptiveMasterService_get_client_presult__isset() : success(false) {}
  bool success;
} _AdaptiveMasterService_get_client_presult__isset;

class AdaptiveMasterService_get_client_presult {
 public:


  virtual ~AdaptiveMasterService_get_client_presult() throw() {}

  std::string* success;

  _AdaptiveMasterService_get_client_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class AdaptiveMasterService_get_client_id_args {
 public:

  AdaptiveMasterService_get_client_id_args() {
  }

  virtual ~AdaptiveMasterService_get_client_id_args() throw() {}


  bool operator == (const AdaptiveMasterService_get_client_id_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AdaptiveMasterService_get_client_id_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdaptiveMasterService_get_client_id_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AdaptiveMasterService_get_client_id_pargs {
 public:


  virtual ~AdaptiveMasterService_get_client_id_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AdaptiveMasterService_get_client_id_result__isset {
  _AdaptiveMasterService_get_client_id_result__isset() : success(false) {}
  bool success;
} _AdaptiveMasterService_get_client_id_result__isset;

class AdaptiveMasterService_get_client_id_result {
 public:

  AdaptiveMasterService_get_client_id_result() : success(0) {
  }

  virtual ~AdaptiveMasterService_get_client_id_result() throw() {}

  int32_t success;

  _AdaptiveMasterService_get_client_id_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const AdaptiveMasterService_get_client_id_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AdaptiveMasterService_get_client_id_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdaptiveMasterService_get_client_id_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AdaptiveMasterService_get_client_id_presult__isset {
  _AdaptiveMasterService_get_client_id_presult__isset() : success(false) {}
  bool success;
} _AdaptiveMasterService_get_client_id_presult__isset;

class AdaptiveMasterService_get_client_id_presult {
 public:


  virtual ~AdaptiveMasterService_get_client_id_presult() throw() {}

  int32_t* success;

  _AdaptiveMasterService_get_client_id_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class AdaptiveMasterServiceClient : virtual public AdaptiveMasterServiceIf {
 public:
  AdaptiveMasterServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  AdaptiveMasterServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void get_client(std::string& _return);
  void send_get_client();
  void recv_get_client(std::string& _return);
  int32_t get_client_id();
  void send_get_client_id();
  int32_t recv_get_client_id();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class AdaptiveMasterServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<AdaptiveMasterServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (AdaptiveMasterServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_get_client(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get_client_id(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  AdaptiveMasterServiceProcessor(boost::shared_ptr<AdaptiveMasterServiceIf> iface) :
    iface_(iface) {
    processMap_["get_client"] = &AdaptiveMasterServiceProcessor::process_get_client;
    processMap_["get_client_id"] = &AdaptiveMasterServiceProcessor::process_get_client_id;
  }

  virtual ~AdaptiveMasterServiceProcessor() {}
};

class AdaptiveMasterServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  AdaptiveMasterServiceProcessorFactory(const ::boost::shared_ptr< AdaptiveMasterServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< AdaptiveMasterServiceIfFactory > handlerFactory_;
};

class AdaptiveMasterServiceMultiface : virtual public AdaptiveMasterServiceIf {
 public:
  AdaptiveMasterServiceMultiface(std::vector<boost::shared_ptr<AdaptiveMasterServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~AdaptiveMasterServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<AdaptiveMasterServiceIf> > ifaces_;
  AdaptiveMasterServiceMultiface() {}
  void add(boost::shared_ptr<AdaptiveMasterServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void get_client(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get_client(_return);
    }
    ifaces_[i]->get_client(_return);
    return;
  }

  int32_t get_client_id() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get_client_id();
    }
    return ifaces_[i]->get_client_id();
  }

};



#endif
