// Generated by gencpp from file event_comm/EventDynamic.msg
// DO NOT EDIT!


#ifndef EVENT_COMM_MESSAGE_EVENTDYNAMIC_H
#define EVENT_COMM_MESSAGE_EVENTDYNAMIC_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <event_comm/EventBase.h>

namespace event_comm
{
template <class ContainerAllocator>
struct EventDynamic_
{
  typedef EventDynamic_<ContainerAllocator> Type;

  EventDynamic_()
    : base()
    , dynamicEventName()
    , dynamicType()
    , dynamicInfo()  {
    }
  EventDynamic_(const ContainerAllocator& _alloc)
    : base(_alloc)
    , dynamicEventName(_alloc)
    , dynamicType(_alloc)
    , dynamicInfo(_alloc)  {
  (void)_alloc;
    }



   typedef  ::event_comm::EventBase_<ContainerAllocator>  _base_type;
  _base_type base;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dynamicEventName_type;
  _dynamicEventName_type dynamicEventName;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dynamicType_type;
  _dynamicType_type dynamicType;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dynamicInfo_type;
  _dynamicInfo_type dynamicInfo;





  typedef boost::shared_ptr< ::event_comm::EventDynamic_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::event_comm::EventDynamic_<ContainerAllocator> const> ConstPtr;

}; // struct EventDynamic_

typedef ::event_comm::EventDynamic_<std::allocator<void> > EventDynamic;

typedef boost::shared_ptr< ::event_comm::EventDynamic > EventDynamicPtr;
typedef boost::shared_ptr< ::event_comm::EventDynamic const> EventDynamicConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::event_comm::EventDynamic_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::event_comm::EventDynamic_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace event_comm

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'event_comm': ['/home/cps/catkin_ws_all_0405/src/gml_verify/micro_embedded_collaborative_engine/event_comm/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::event_comm::EventDynamic_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::event_comm::EventDynamic_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::event_comm::EventDynamic_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::event_comm::EventDynamic_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::event_comm::EventDynamic_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::event_comm::EventDynamic_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::event_comm::EventDynamic_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ccc20968a7c0d24ca90b858f3122b4b";
  }

  static const char* value(const ::event_comm::EventDynamic_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ccc20968a7c0d24ULL;
  static const uint64_t static_value2 = 0xca90b858f3122b4bULL;
};

template<class ContainerAllocator>
struct DataType< ::event_comm::EventDynamic_<ContainerAllocator> >
{
  static const char* value()
  {
    return "event_comm/EventDynamic";
  }

  static const char* value(const ::event_comm::EventDynamic_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::event_comm::EventDynamic_<ContainerAllocator> >
{
  static const char* value()
  {
    return "event_comm/EventBase base\n\
string dynamicEventName\n\
string dynamicType\n\
string dynamicInfo\n\
================================================================================\n\
MSG: event_comm/EventBase\n\
std_msgs/Header header\n\
string eventID\n\
string source\n\
time begintime\n\
time endtime\n\
geometry_msgs/Point startPoint\n\
geometry_msgs/Point endPoint\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::event_comm::EventDynamic_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::event_comm::EventDynamic_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.base);
      stream.next(m.dynamicEventName);
      stream.next(m.dynamicType);
      stream.next(m.dynamicInfo);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EventDynamic_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::event_comm::EventDynamic_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::event_comm::EventDynamic_<ContainerAllocator>& v)
  {
    s << indent << "base: ";
    s << std::endl;
    Printer< ::event_comm::EventBase_<ContainerAllocator> >::stream(s, indent + "  ", v.base);
    s << indent << "dynamicEventName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dynamicEventName);
    s << indent << "dynamicType: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dynamicType);
    s << indent << "dynamicInfo: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dynamicInfo);
  }
};

} // namespace message_operations
} // namespace ros

#endif // EVENT_COMM_MESSAGE_EVENTDYNAMIC_H
