/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Handler_H
#define Handler_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "handler_types.h"

namespace succinct {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class HandlerIf {
 public:
  virtual ~HandlerIf() {}
  virtual int32_t ConnectToHandlers() = 0;
  virtual int32_t DisconnectFromHandlers() = 0;
  virtual int32_t ConnectToLocalServers() = 0;
  virtual int32_t DisconnectFromLocalServers() = 0;
  virtual int32_t StartLocalServers() = 0;
  virtual void Get(std::string& _return, const int64_t key) = 0;
  virtual void GetLocal(std::string& _return, const int32_t qserver_id, const int64_t key) = 0;
  virtual void Search(std::set<int64_t> & _return, const std::string& query) = 0;
  virtual void SearchLocal(std::set<int64_t> & _return, const std::string& query) = 0;
  virtual void GetHeartBeat( ::HeartBeat& _return) = 0;
};

class HandlerIfFactory {
 public:
  typedef HandlerIf Handler;

  virtual ~HandlerIfFactory() {}

  virtual HandlerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(HandlerIf* /* handler */) = 0;
};

class HandlerIfSingletonFactory : virtual public HandlerIfFactory {
 public:
  HandlerIfSingletonFactory(const boost::shared_ptr<HandlerIf>& iface) : iface_(iface) {}
  virtual ~HandlerIfSingletonFactory() {}

  virtual HandlerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(HandlerIf* /* handler */) {}

 protected:
  boost::shared_ptr<HandlerIf> iface_;
};

class HandlerNull : virtual public HandlerIf {
 public:
  virtual ~HandlerNull() {}
  int32_t ConnectToHandlers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t DisconnectFromHandlers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t ConnectToLocalServers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t DisconnectFromLocalServers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t StartLocalServers() {
    int32_t _return = 0;
    return _return;
  }
  void Get(std::string& /* _return */, const int64_t /* key */) {
    return;
  }
  void GetLocal(std::string& /* _return */, const int32_t /* qserver_id */, const int64_t /* key */) {
    return;
  }
  void Search(std::set<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void SearchLocal(std::set<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void GetHeartBeat( ::HeartBeat& /* _return */) {
    return;
  }
};


class Handler_ConnectToHandlers_args {
 public:

  Handler_ConnectToHandlers_args(const Handler_ConnectToHandlers_args&);
  Handler_ConnectToHandlers_args& operator=(const Handler_ConnectToHandlers_args&);
  Handler_ConnectToHandlers_args() {
  }

  virtual ~Handler_ConnectToHandlers_args() throw();

  bool operator == (const Handler_ConnectToHandlers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_ConnectToHandlers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_ConnectToHandlers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_ConnectToHandlers_pargs {
 public:


  virtual ~Handler_ConnectToHandlers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_ConnectToHandlers_result__isset {
  _Handler_ConnectToHandlers_result__isset() : success(false) {}
  bool success :1;
} _Handler_ConnectToHandlers_result__isset;

class Handler_ConnectToHandlers_result {
 public:

  Handler_ConnectToHandlers_result(const Handler_ConnectToHandlers_result&);
  Handler_ConnectToHandlers_result& operator=(const Handler_ConnectToHandlers_result&);
  Handler_ConnectToHandlers_result() : success(0) {
  }

  virtual ~Handler_ConnectToHandlers_result() throw();
  int32_t success;

  _Handler_ConnectToHandlers_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Handler_ConnectToHandlers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_ConnectToHandlers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_ConnectToHandlers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_ConnectToHandlers_presult__isset {
  _Handler_ConnectToHandlers_presult__isset() : success(false) {}
  bool success :1;
} _Handler_ConnectToHandlers_presult__isset;

class Handler_ConnectToHandlers_presult {
 public:


  virtual ~Handler_ConnectToHandlers_presult() throw();
  int32_t* success;

  _Handler_ConnectToHandlers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Handler_DisconnectFromHandlers_args {
 public:

  Handler_DisconnectFromHandlers_args(const Handler_DisconnectFromHandlers_args&);
  Handler_DisconnectFromHandlers_args& operator=(const Handler_DisconnectFromHandlers_args&);
  Handler_DisconnectFromHandlers_args() {
  }

  virtual ~Handler_DisconnectFromHandlers_args() throw();

  bool operator == (const Handler_DisconnectFromHandlers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_DisconnectFromHandlers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_DisconnectFromHandlers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_DisconnectFromHandlers_pargs {
 public:


  virtual ~Handler_DisconnectFromHandlers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_DisconnectFromHandlers_result__isset {
  _Handler_DisconnectFromHandlers_result__isset() : success(false) {}
  bool success :1;
} _Handler_DisconnectFromHandlers_result__isset;

class Handler_DisconnectFromHandlers_result {
 public:

  Handler_DisconnectFromHandlers_result(const Handler_DisconnectFromHandlers_result&);
  Handler_DisconnectFromHandlers_result& operator=(const Handler_DisconnectFromHandlers_result&);
  Handler_DisconnectFromHandlers_result() : success(0) {
  }

  virtual ~Handler_DisconnectFromHandlers_result() throw();
  int32_t success;

  _Handler_DisconnectFromHandlers_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Handler_DisconnectFromHandlers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_DisconnectFromHandlers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_DisconnectFromHandlers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_DisconnectFromHandlers_presult__isset {
  _Handler_DisconnectFromHandlers_presult__isset() : success(false) {}
  bool success :1;
} _Handler_DisconnectFromHandlers_presult__isset;

class Handler_DisconnectFromHandlers_presult {
 public:


  virtual ~Handler_DisconnectFromHandlers_presult() throw();
  int32_t* success;

  _Handler_DisconnectFromHandlers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Handler_ConnectToLocalServers_args {
 public:

  Handler_ConnectToLocalServers_args(const Handler_ConnectToLocalServers_args&);
  Handler_ConnectToLocalServers_args& operator=(const Handler_ConnectToLocalServers_args&);
  Handler_ConnectToLocalServers_args() {
  }

  virtual ~Handler_ConnectToLocalServers_args() throw();

  bool operator == (const Handler_ConnectToLocalServers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_ConnectToLocalServers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_ConnectToLocalServers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_ConnectToLocalServers_pargs {
 public:


  virtual ~Handler_ConnectToLocalServers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_ConnectToLocalServers_result__isset {
  _Handler_ConnectToLocalServers_result__isset() : success(false) {}
  bool success :1;
} _Handler_ConnectToLocalServers_result__isset;

class Handler_ConnectToLocalServers_result {
 public:

  Handler_ConnectToLocalServers_result(const Handler_ConnectToLocalServers_result&);
  Handler_ConnectToLocalServers_result& operator=(const Handler_ConnectToLocalServers_result&);
  Handler_ConnectToLocalServers_result() : success(0) {
  }

  virtual ~Handler_ConnectToLocalServers_result() throw();
  int32_t success;

  _Handler_ConnectToLocalServers_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Handler_ConnectToLocalServers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_ConnectToLocalServers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_ConnectToLocalServers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_ConnectToLocalServers_presult__isset {
  _Handler_ConnectToLocalServers_presult__isset() : success(false) {}
  bool success :1;
} _Handler_ConnectToLocalServers_presult__isset;

class Handler_ConnectToLocalServers_presult {
 public:


  virtual ~Handler_ConnectToLocalServers_presult() throw();
  int32_t* success;

  _Handler_ConnectToLocalServers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Handler_DisconnectFromLocalServers_args {
 public:

  Handler_DisconnectFromLocalServers_args(const Handler_DisconnectFromLocalServers_args&);
  Handler_DisconnectFromLocalServers_args& operator=(const Handler_DisconnectFromLocalServers_args&);
  Handler_DisconnectFromLocalServers_args() {
  }

  virtual ~Handler_DisconnectFromLocalServers_args() throw();

  bool operator == (const Handler_DisconnectFromLocalServers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_DisconnectFromLocalServers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_DisconnectFromLocalServers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_DisconnectFromLocalServers_pargs {
 public:


  virtual ~Handler_DisconnectFromLocalServers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_DisconnectFromLocalServers_result__isset {
  _Handler_DisconnectFromLocalServers_result__isset() : success(false) {}
  bool success :1;
} _Handler_DisconnectFromLocalServers_result__isset;

class Handler_DisconnectFromLocalServers_result {
 public:

  Handler_DisconnectFromLocalServers_result(const Handler_DisconnectFromLocalServers_result&);
  Handler_DisconnectFromLocalServers_result& operator=(const Handler_DisconnectFromLocalServers_result&);
  Handler_DisconnectFromLocalServers_result() : success(0) {
  }

  virtual ~Handler_DisconnectFromLocalServers_result() throw();
  int32_t success;

  _Handler_DisconnectFromLocalServers_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Handler_DisconnectFromLocalServers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_DisconnectFromLocalServers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_DisconnectFromLocalServers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_DisconnectFromLocalServers_presult__isset {
  _Handler_DisconnectFromLocalServers_presult__isset() : success(false) {}
  bool success :1;
} _Handler_DisconnectFromLocalServers_presult__isset;

class Handler_DisconnectFromLocalServers_presult {
 public:


  virtual ~Handler_DisconnectFromLocalServers_presult() throw();
  int32_t* success;

  _Handler_DisconnectFromLocalServers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Handler_StartLocalServers_args {
 public:

  Handler_StartLocalServers_args(const Handler_StartLocalServers_args&);
  Handler_StartLocalServers_args& operator=(const Handler_StartLocalServers_args&);
  Handler_StartLocalServers_args() {
  }

  virtual ~Handler_StartLocalServers_args() throw();

  bool operator == (const Handler_StartLocalServers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_StartLocalServers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_StartLocalServers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_StartLocalServers_pargs {
 public:


  virtual ~Handler_StartLocalServers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_StartLocalServers_result__isset {
  _Handler_StartLocalServers_result__isset() : success(false) {}
  bool success :1;
} _Handler_StartLocalServers_result__isset;

class Handler_StartLocalServers_result {
 public:

  Handler_StartLocalServers_result(const Handler_StartLocalServers_result&);
  Handler_StartLocalServers_result& operator=(const Handler_StartLocalServers_result&);
  Handler_StartLocalServers_result() : success(0) {
  }

  virtual ~Handler_StartLocalServers_result() throw();
  int32_t success;

  _Handler_StartLocalServers_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Handler_StartLocalServers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_StartLocalServers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_StartLocalServers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_StartLocalServers_presult__isset {
  _Handler_StartLocalServers_presult__isset() : success(false) {}
  bool success :1;
} _Handler_StartLocalServers_presult__isset;

class Handler_StartLocalServers_presult {
 public:


  virtual ~Handler_StartLocalServers_presult() throw();
  int32_t* success;

  _Handler_StartLocalServers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Handler_Get_args__isset {
  _Handler_Get_args__isset() : key(false) {}
  bool key :1;
} _Handler_Get_args__isset;

class Handler_Get_args {
 public:

  Handler_Get_args(const Handler_Get_args&);
  Handler_Get_args& operator=(const Handler_Get_args&);
  Handler_Get_args() : key(0) {
  }

  virtual ~Handler_Get_args() throw();
  int64_t key;

  _Handler_Get_args__isset __isset;

  void __set_key(const int64_t val);

  bool operator == (const Handler_Get_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Handler_Get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_Get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_Get_pargs {
 public:


  virtual ~Handler_Get_pargs() throw();
  const int64_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_Get_result__isset {
  _Handler_Get_result__isset() : success(false) {}
  bool success :1;
} _Handler_Get_result__isset;

class Handler_Get_result {
 public:

  Handler_Get_result(const Handler_Get_result&);
  Handler_Get_result& operator=(const Handler_Get_result&);
  Handler_Get_result() : success() {
  }

  virtual ~Handler_Get_result() throw();
  std::string success;

  _Handler_Get_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Handler_Get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_Get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_Get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_Get_presult__isset {
  _Handler_Get_presult__isset() : success(false) {}
  bool success :1;
} _Handler_Get_presult__isset;

class Handler_Get_presult {
 public:


  virtual ~Handler_Get_presult() throw();
  std::string* success;

  _Handler_Get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Handler_GetLocal_args__isset {
  _Handler_GetLocal_args__isset() : qserver_id(false), key(false) {}
  bool qserver_id :1;
  bool key :1;
} _Handler_GetLocal_args__isset;

class Handler_GetLocal_args {
 public:

  Handler_GetLocal_args(const Handler_GetLocal_args&);
  Handler_GetLocal_args& operator=(const Handler_GetLocal_args&);
  Handler_GetLocal_args() : qserver_id(0), key(0) {
  }

  virtual ~Handler_GetLocal_args() throw();
  int32_t qserver_id;
  int64_t key;

  _Handler_GetLocal_args__isset __isset;

  void __set_qserver_id(const int32_t val);

  void __set_key(const int64_t val);

  bool operator == (const Handler_GetLocal_args & rhs) const
  {
    if (!(qserver_id == rhs.qserver_id))
      return false;
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Handler_GetLocal_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_GetLocal_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_GetLocal_pargs {
 public:


  virtual ~Handler_GetLocal_pargs() throw();
  const int32_t* qserver_id;
  const int64_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_GetLocal_result__isset {
  _Handler_GetLocal_result__isset() : success(false) {}
  bool success :1;
} _Handler_GetLocal_result__isset;

class Handler_GetLocal_result {
 public:

  Handler_GetLocal_result(const Handler_GetLocal_result&);
  Handler_GetLocal_result& operator=(const Handler_GetLocal_result&);
  Handler_GetLocal_result() : success() {
  }

  virtual ~Handler_GetLocal_result() throw();
  std::string success;

  _Handler_GetLocal_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Handler_GetLocal_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_GetLocal_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_GetLocal_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_GetLocal_presult__isset {
  _Handler_GetLocal_presult__isset() : success(false) {}
  bool success :1;
} _Handler_GetLocal_presult__isset;

class Handler_GetLocal_presult {
 public:


  virtual ~Handler_GetLocal_presult() throw();
  std::string* success;

  _Handler_GetLocal_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Handler_Search_args__isset {
  _Handler_Search_args__isset() : query(false) {}
  bool query :1;
} _Handler_Search_args__isset;

class Handler_Search_args {
 public:

  Handler_Search_args(const Handler_Search_args&);
  Handler_Search_args& operator=(const Handler_Search_args&);
  Handler_Search_args() : query() {
  }

  virtual ~Handler_Search_args() throw();
  std::string query;

  _Handler_Search_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const Handler_Search_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const Handler_Search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_Search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_Search_pargs {
 public:


  virtual ~Handler_Search_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_Search_result__isset {
  _Handler_Search_result__isset() : success(false) {}
  bool success :1;
} _Handler_Search_result__isset;

class Handler_Search_result {
 public:

  Handler_Search_result(const Handler_Search_result&);
  Handler_Search_result& operator=(const Handler_Search_result&);
  Handler_Search_result() {
  }

  virtual ~Handler_Search_result() throw();
  std::set<int64_t>  success;

  _Handler_Search_result__isset __isset;

  void __set_success(const std::set<int64_t> & val);

  bool operator == (const Handler_Search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_Search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_Search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_Search_presult__isset {
  _Handler_Search_presult__isset() : success(false) {}
  bool success :1;
} _Handler_Search_presult__isset;

class Handler_Search_presult {
 public:


  virtual ~Handler_Search_presult() throw();
  std::set<int64_t> * success;

  _Handler_Search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Handler_SearchLocal_args__isset {
  _Handler_SearchLocal_args__isset() : query(false) {}
  bool query :1;
} _Handler_SearchLocal_args__isset;

class Handler_SearchLocal_args {
 public:

  Handler_SearchLocal_args(const Handler_SearchLocal_args&);
  Handler_SearchLocal_args& operator=(const Handler_SearchLocal_args&);
  Handler_SearchLocal_args() : query() {
  }

  virtual ~Handler_SearchLocal_args() throw();
  std::string query;

  _Handler_SearchLocal_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const Handler_SearchLocal_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const Handler_SearchLocal_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_SearchLocal_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_SearchLocal_pargs {
 public:


  virtual ~Handler_SearchLocal_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_SearchLocal_result__isset {
  _Handler_SearchLocal_result__isset() : success(false) {}
  bool success :1;
} _Handler_SearchLocal_result__isset;

class Handler_SearchLocal_result {
 public:

  Handler_SearchLocal_result(const Handler_SearchLocal_result&);
  Handler_SearchLocal_result& operator=(const Handler_SearchLocal_result&);
  Handler_SearchLocal_result() {
  }

  virtual ~Handler_SearchLocal_result() throw();
  std::set<int64_t>  success;

  _Handler_SearchLocal_result__isset __isset;

  void __set_success(const std::set<int64_t> & val);

  bool operator == (const Handler_SearchLocal_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_SearchLocal_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_SearchLocal_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_SearchLocal_presult__isset {
  _Handler_SearchLocal_presult__isset() : success(false) {}
  bool success :1;
} _Handler_SearchLocal_presult__isset;

class Handler_SearchLocal_presult {
 public:


  virtual ~Handler_SearchLocal_presult() throw();
  std::set<int64_t> * success;

  _Handler_SearchLocal_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Handler_GetHeartBeat_args {
 public:

  Handler_GetHeartBeat_args(const Handler_GetHeartBeat_args&);
  Handler_GetHeartBeat_args& operator=(const Handler_GetHeartBeat_args&);
  Handler_GetHeartBeat_args() {
  }

  virtual ~Handler_GetHeartBeat_args() throw();

  bool operator == (const Handler_GetHeartBeat_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Handler_GetHeartBeat_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_GetHeartBeat_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Handler_GetHeartBeat_pargs {
 public:


  virtual ~Handler_GetHeartBeat_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_GetHeartBeat_result__isset {
  _Handler_GetHeartBeat_result__isset() : success(false) {}
  bool success :1;
} _Handler_GetHeartBeat_result__isset;

class Handler_GetHeartBeat_result {
 public:

  Handler_GetHeartBeat_result(const Handler_GetHeartBeat_result&);
  Handler_GetHeartBeat_result& operator=(const Handler_GetHeartBeat_result&);
  Handler_GetHeartBeat_result() {
  }

  virtual ~Handler_GetHeartBeat_result() throw();
   ::HeartBeat success;

  _Handler_GetHeartBeat_result__isset __isset;

  void __set_success(const  ::HeartBeat& val);

  bool operator == (const Handler_GetHeartBeat_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Handler_GetHeartBeat_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Handler_GetHeartBeat_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Handler_GetHeartBeat_presult__isset {
  _Handler_GetHeartBeat_presult__isset() : success(false) {}
  bool success :1;
} _Handler_GetHeartBeat_presult__isset;

class Handler_GetHeartBeat_presult {
 public:


  virtual ~Handler_GetHeartBeat_presult() throw();
   ::HeartBeat* success;

  _Handler_GetHeartBeat_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class HandlerClient : virtual public HandlerIf {
 public:
  HandlerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HandlerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t ConnectToHandlers();
  void send_ConnectToHandlers();
  int32_t recv_ConnectToHandlers();
  int32_t DisconnectFromHandlers();
  void send_DisconnectFromHandlers();
  int32_t recv_DisconnectFromHandlers();
  int32_t ConnectToLocalServers();
  void send_ConnectToLocalServers();
  int32_t recv_ConnectToLocalServers();
  int32_t DisconnectFromLocalServers();
  void send_DisconnectFromLocalServers();
  int32_t recv_DisconnectFromLocalServers();
  int32_t StartLocalServers();
  void send_StartLocalServers();
  int32_t recv_StartLocalServers();
  void Get(std::string& _return, const int64_t key);
  void send_Get(const int64_t key);
  void recv_Get(std::string& _return);
  void GetLocal(std::string& _return, const int32_t qserver_id, const int64_t key);
  void send_GetLocal(const int32_t qserver_id, const int64_t key);
  void recv_GetLocal(std::string& _return);
  void Search(std::set<int64_t> & _return, const std::string& query);
  void send_Search(const std::string& query);
  void recv_Search(std::set<int64_t> & _return);
  void SearchLocal(std::set<int64_t> & _return, const std::string& query);
  void send_SearchLocal(const std::string& query);
  void recv_SearchLocal(std::set<int64_t> & _return);
  void GetHeartBeat( ::HeartBeat& _return);
  void send_GetHeartBeat();
  void recv_GetHeartBeat( ::HeartBeat& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class HandlerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<HandlerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (HandlerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ConnectToHandlers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DisconnectFromHandlers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ConnectToLocalServers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DisconnectFromLocalServers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_StartLocalServers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetLocal(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_SearchLocal(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetHeartBeat(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  HandlerProcessor(boost::shared_ptr<HandlerIf> iface) :
    iface_(iface) {
    processMap_["ConnectToHandlers"] = &HandlerProcessor::process_ConnectToHandlers;
    processMap_["DisconnectFromHandlers"] = &HandlerProcessor::process_DisconnectFromHandlers;
    processMap_["ConnectToLocalServers"] = &HandlerProcessor::process_ConnectToLocalServers;
    processMap_["DisconnectFromLocalServers"] = &HandlerProcessor::process_DisconnectFromLocalServers;
    processMap_["StartLocalServers"] = &HandlerProcessor::process_StartLocalServers;
    processMap_["Get"] = &HandlerProcessor::process_Get;
    processMap_["GetLocal"] = &HandlerProcessor::process_GetLocal;
    processMap_["Search"] = &HandlerProcessor::process_Search;
    processMap_["SearchLocal"] = &HandlerProcessor::process_SearchLocal;
    processMap_["GetHeartBeat"] = &HandlerProcessor::process_GetHeartBeat;
  }

  virtual ~HandlerProcessor() {}
};

class HandlerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  HandlerProcessorFactory(const ::boost::shared_ptr< HandlerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< HandlerIfFactory > handlerFactory_;
};

class HandlerMultiface : virtual public HandlerIf {
 public:
  HandlerMultiface(std::vector<boost::shared_ptr<HandlerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~HandlerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<HandlerIf> > ifaces_;
  HandlerMultiface() {}
  void add(boost::shared_ptr<HandlerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t ConnectToHandlers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ConnectToHandlers();
    }
    return ifaces_[i]->ConnectToHandlers();
  }

  int32_t DisconnectFromHandlers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DisconnectFromHandlers();
    }
    return ifaces_[i]->DisconnectFromHandlers();
  }

  int32_t ConnectToLocalServers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ConnectToLocalServers();
    }
    return ifaces_[i]->ConnectToLocalServers();
  }

  int32_t DisconnectFromLocalServers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DisconnectFromLocalServers();
    }
    return ifaces_[i]->DisconnectFromLocalServers();
  }

  int32_t StartLocalServers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->StartLocalServers();
    }
    return ifaces_[i]->StartLocalServers();
  }

  void Get(std::string& _return, const int64_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Get(_return, key);
    }
    ifaces_[i]->Get(_return, key);
    return;
  }

  void GetLocal(std::string& _return, const int32_t qserver_id, const int64_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetLocal(_return, qserver_id, key);
    }
    ifaces_[i]->GetLocal(_return, qserver_id, key);
    return;
  }

  void Search(std::set<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Search(_return, query);
    }
    ifaces_[i]->Search(_return, query);
    return;
  }

  void SearchLocal(std::set<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->SearchLocal(_return, query);
    }
    ifaces_[i]->SearchLocal(_return, query);
    return;
  }

  void GetHeartBeat( ::HeartBeat& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetHeartBeat(_return);
    }
    ifaces_[i]->GetHeartBeat(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class HandlerConcurrentClient : virtual public HandlerIf {
 public:
  HandlerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HandlerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t ConnectToHandlers();
  int32_t send_ConnectToHandlers();
  int32_t recv_ConnectToHandlers(const int32_t seqid);
  int32_t DisconnectFromHandlers();
  int32_t send_DisconnectFromHandlers();
  int32_t recv_DisconnectFromHandlers(const int32_t seqid);
  int32_t ConnectToLocalServers();
  int32_t send_ConnectToLocalServers();
  int32_t recv_ConnectToLocalServers(const int32_t seqid);
  int32_t DisconnectFromLocalServers();
  int32_t send_DisconnectFromLocalServers();
  int32_t recv_DisconnectFromLocalServers(const int32_t seqid);
  int32_t StartLocalServers();
  int32_t send_StartLocalServers();
  int32_t recv_StartLocalServers(const int32_t seqid);
  void Get(std::string& _return, const int64_t key);
  int32_t send_Get(const int64_t key);
  void recv_Get(std::string& _return, const int32_t seqid);
  void GetLocal(std::string& _return, const int32_t qserver_id, const int64_t key);
  int32_t send_GetLocal(const int32_t qserver_id, const int64_t key);
  void recv_GetLocal(std::string& _return, const int32_t seqid);
  void Search(std::set<int64_t> & _return, const std::string& query);
  int32_t send_Search(const std::string& query);
  void recv_Search(std::set<int64_t> & _return, const int32_t seqid);
  void SearchLocal(std::set<int64_t> & _return, const std::string& query);
  int32_t send_SearchLocal(const std::string& query);
  void recv_SearchLocal(std::set<int64_t> & _return, const int32_t seqid);
  void GetHeartBeat( ::HeartBeat& _return);
  int32_t send_GetHeartBeat();
  void recv_GetHeartBeat( ::HeartBeat& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif