// Generated by gencpp from file dji_sdk/SDKControlAuthorityRequest.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_SDKCONTROLAUTHORITYREQUEST_H
#define DJI_SDK_MESSAGE_SDKCONTROLAUTHORITYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_sdk
{
template <class ContainerAllocator>
struct SDKControlAuthorityRequest_
{
  typedef SDKControlAuthorityRequest_<ContainerAllocator> Type;

  SDKControlAuthorityRequest_()
    : control_enable(0)  {
    }
  SDKControlAuthorityRequest_(const ContainerAllocator& _alloc)
    : control_enable(0)  {
  (void)_alloc;
    }



   typedef uint8_t _control_enable_type;
  _control_enable_type control_enable;



  enum {
    RELEASE_CONTROL = 0u,
    REQUEST_CONTROL = 1u,
  };


  typedef boost::shared_ptr< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SDKControlAuthorityRequest_

typedef ::dji_sdk::SDKControlAuthorityRequest_<std::allocator<void> > SDKControlAuthorityRequest;

typedef boost::shared_ptr< ::dji_sdk::SDKControlAuthorityRequest > SDKControlAuthorityRequestPtr;
typedef boost::shared_ptr< ::dji_sdk::SDKControlAuthorityRequest const> SDKControlAuthorityRequestConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/cps/catkin_ws_all_0405/src/gml_verify/libraries/onboard_sdk_ros/dji_sdk/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4be067264420fcea65acedecc46466bd";
  }

  static const char* value(const ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4be067264420fceaULL;
  static const uint64_t static_value2 = 0x65acedecc46466bdULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/SDKControlAuthorityRequest";
  }

  static const char* value(const ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
uint8 RELEASE_CONTROL = 0\n\
uint8 REQUEST_CONTROL = 1\n\
\n\
\n\
uint8 control_enable\n\
";
  }

  static const char* value(const ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.control_enable);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SDKControlAuthorityRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::SDKControlAuthorityRequest_<ContainerAllocator>& v)
  {
    s << indent << "control_enable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.control_enable);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_SDKCONTROLAUTHORITYREQUEST_H
