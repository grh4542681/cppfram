// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_header.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_5fheader_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_5fheader_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "message_id.pb.h"
#include "message_appid.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_5fheader_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_5fheader_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_5fheader_2eproto;
namespace message {
namespace protobuf {
class MessageHeaderProtobuf;
class MessageHeaderProtobufDefaultTypeInternal;
extern MessageHeaderProtobufDefaultTypeInternal _MessageHeaderProtobuf_default_instance_;
}  // namespace protobuf
}  // namespace message
PROTOBUF_NAMESPACE_OPEN
template<> ::message::protobuf::MessageHeaderProtobuf* Arena::CreateMaybeMessage<::message::protobuf::MessageHeaderProtobuf>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace message {
namespace protobuf {

// ===================================================================

class MessageHeaderProtobuf :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:message.protobuf.MessageHeaderProtobuf) */ {
 public:
  MessageHeaderProtobuf();
  virtual ~MessageHeaderProtobuf();

  MessageHeaderProtobuf(const MessageHeaderProtobuf& from);
  MessageHeaderProtobuf(MessageHeaderProtobuf&& from) noexcept
    : MessageHeaderProtobuf() {
    *this = ::std::move(from);
  }

  inline MessageHeaderProtobuf& operator=(const MessageHeaderProtobuf& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageHeaderProtobuf& operator=(MessageHeaderProtobuf&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const MessageHeaderProtobuf& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MessageHeaderProtobuf* internal_default_instance() {
    return reinterpret_cast<const MessageHeaderProtobuf*>(
               &_MessageHeaderProtobuf_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MessageHeaderProtobuf& a, MessageHeaderProtobuf& b) {
    a.Swap(&b);
  }
  inline void Swap(MessageHeaderProtobuf* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MessageHeaderProtobuf* New() const final {
    return CreateMaybeMessage<MessageHeaderProtobuf>(nullptr);
  }

  MessageHeaderProtobuf* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MessageHeaderProtobuf>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const MessageHeaderProtobuf& from);
  void MergeFrom(const MessageHeaderProtobuf& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MessageHeaderProtobuf* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "message.protobuf.MessageHeaderProtobuf";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_message_5fheader_2eproto);
    return ::descriptor_table_message_5fheader_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMidFieldNumber = 1,
    kAppidFieldNumber = 2,
    kBodyLenFieldNumber = 3,
  };
  // .message.protobuf.MessageIdProtobuf mid = 1;
  bool has_mid() const;
  private:
  bool _internal_has_mid() const;
  public:
  void clear_mid();
  const ::message::protobuf::MessageIdProtobuf& mid() const;
  ::message::protobuf::MessageIdProtobuf* release_mid();
  ::message::protobuf::MessageIdProtobuf* mutable_mid();
  void set_allocated_mid(::message::protobuf::MessageIdProtobuf* mid);
  private:
  const ::message::protobuf::MessageIdProtobuf& _internal_mid() const;
  ::message::protobuf::MessageIdProtobuf* _internal_mutable_mid();
  public:

  // .message.protobuf.MessageAppidProtobuf appid = 2;
  bool has_appid() const;
  private:
  bool _internal_has_appid() const;
  public:
  void clear_appid();
  const ::message::protobuf::MessageAppidProtobuf& appid() const;
  ::message::protobuf::MessageAppidProtobuf* release_appid();
  ::message::protobuf::MessageAppidProtobuf* mutable_appid();
  void set_allocated_appid(::message::protobuf::MessageAppidProtobuf* appid);
  private:
  const ::message::protobuf::MessageAppidProtobuf& _internal_appid() const;
  ::message::protobuf::MessageAppidProtobuf* _internal_mutable_appid();
  public:

  // uint32 body_len = 3;
  void clear_body_len();
  ::PROTOBUF_NAMESPACE_ID::uint32 body_len() const;
  void set_body_len(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_body_len() const;
  void _internal_set_body_len(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:message.protobuf.MessageHeaderProtobuf)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::message::protobuf::MessageIdProtobuf* mid_;
  ::message::protobuf::MessageAppidProtobuf* appid_;
  ::PROTOBUF_NAMESPACE_ID::uint32 body_len_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_5fheader_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MessageHeaderProtobuf

// .message.protobuf.MessageIdProtobuf mid = 1;
inline bool MessageHeaderProtobuf::_internal_has_mid() const {
  return this != internal_default_instance() && mid_ != nullptr;
}
inline bool MessageHeaderProtobuf::has_mid() const {
  return _internal_has_mid();
}
inline const ::message::protobuf::MessageIdProtobuf& MessageHeaderProtobuf::_internal_mid() const {
  const ::message::protobuf::MessageIdProtobuf* p = mid_;
  return p != nullptr ? *p : *reinterpret_cast<const ::message::protobuf::MessageIdProtobuf*>(
      &::message::protobuf::_MessageIdProtobuf_default_instance_);
}
inline const ::message::protobuf::MessageIdProtobuf& MessageHeaderProtobuf::mid() const {
  // @@protoc_insertion_point(field_get:message.protobuf.MessageHeaderProtobuf.mid)
  return _internal_mid();
}
inline ::message::protobuf::MessageIdProtobuf* MessageHeaderProtobuf::release_mid() {
  // @@protoc_insertion_point(field_release:message.protobuf.MessageHeaderProtobuf.mid)
  
  ::message::protobuf::MessageIdProtobuf* temp = mid_;
  mid_ = nullptr;
  return temp;
}
inline ::message::protobuf::MessageIdProtobuf* MessageHeaderProtobuf::_internal_mutable_mid() {
  
  if (mid_ == nullptr) {
    auto* p = CreateMaybeMessage<::message::protobuf::MessageIdProtobuf>(GetArenaNoVirtual());
    mid_ = p;
  }
  return mid_;
}
inline ::message::protobuf::MessageIdProtobuf* MessageHeaderProtobuf::mutable_mid() {
  // @@protoc_insertion_point(field_mutable:message.protobuf.MessageHeaderProtobuf.mid)
  return _internal_mutable_mid();
}
inline void MessageHeaderProtobuf::set_allocated_mid(::message::protobuf::MessageIdProtobuf* mid) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(mid_);
  }
  if (mid) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      mid = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, mid, submessage_arena);
    }
    
  } else {
    
  }
  mid_ = mid;
  // @@protoc_insertion_point(field_set_allocated:message.protobuf.MessageHeaderProtobuf.mid)
}

// .message.protobuf.MessageAppidProtobuf appid = 2;
inline bool MessageHeaderProtobuf::_internal_has_appid() const {
  return this != internal_default_instance() && appid_ != nullptr;
}
inline bool MessageHeaderProtobuf::has_appid() const {
  return _internal_has_appid();
}
inline const ::message::protobuf::MessageAppidProtobuf& MessageHeaderProtobuf::_internal_appid() const {
  const ::message::protobuf::MessageAppidProtobuf* p = appid_;
  return p != nullptr ? *p : *reinterpret_cast<const ::message::protobuf::MessageAppidProtobuf*>(
      &::message::protobuf::_MessageAppidProtobuf_default_instance_);
}
inline const ::message::protobuf::MessageAppidProtobuf& MessageHeaderProtobuf::appid() const {
  // @@protoc_insertion_point(field_get:message.protobuf.MessageHeaderProtobuf.appid)
  return _internal_appid();
}
inline ::message::protobuf::MessageAppidProtobuf* MessageHeaderProtobuf::release_appid() {
  // @@protoc_insertion_point(field_release:message.protobuf.MessageHeaderProtobuf.appid)
  
  ::message::protobuf::MessageAppidProtobuf* temp = appid_;
  appid_ = nullptr;
  return temp;
}
inline ::message::protobuf::MessageAppidProtobuf* MessageHeaderProtobuf::_internal_mutable_appid() {
  
  if (appid_ == nullptr) {
    auto* p = CreateMaybeMessage<::message::protobuf::MessageAppidProtobuf>(GetArenaNoVirtual());
    appid_ = p;
  }
  return appid_;
}
inline ::message::protobuf::MessageAppidProtobuf* MessageHeaderProtobuf::mutable_appid() {
  // @@protoc_insertion_point(field_mutable:message.protobuf.MessageHeaderProtobuf.appid)
  return _internal_mutable_appid();
}
inline void MessageHeaderProtobuf::set_allocated_appid(::message::protobuf::MessageAppidProtobuf* appid) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(appid_);
  }
  if (appid) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      appid = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, appid, submessage_arena);
    }
    
  } else {
    
  }
  appid_ = appid;
  // @@protoc_insertion_point(field_set_allocated:message.protobuf.MessageHeaderProtobuf.appid)
}

// uint32 body_len = 3;
inline void MessageHeaderProtobuf::clear_body_len() {
  body_len_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MessageHeaderProtobuf::_internal_body_len() const {
  return body_len_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MessageHeaderProtobuf::body_len() const {
  // @@protoc_insertion_point(field_get:message.protobuf.MessageHeaderProtobuf.body_len)
  return _internal_body_len();
}
inline void MessageHeaderProtobuf::_internal_set_body_len(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  body_len_ = value;
}
inline void MessageHeaderProtobuf::set_body_len(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_body_len(value);
  // @@protoc_insertion_point(field_set:message.protobuf.MessageHeaderProtobuf.body_len)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace message

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_5fheader_2eproto