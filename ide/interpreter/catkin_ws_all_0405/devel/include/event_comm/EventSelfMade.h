// Generated by gencpp from file event_comm/EventSelfMade.msg
// DO NOT EDIT!


#ifndef EVENT_COMM_MESSAGE_EVENTSELFMADE_H
#define EVENT_COMM_MESSAGE_EVENTSELFMADE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace event_comm
{
template <class ContainerAllocator>
struct EventSelfMade_
{
  typedef EventSelfMade_<ContainerAllocator> Type;

  EventSelfMade_()
    {
    }
  EventSelfMade_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::event_comm::EventSelfMade_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::event_comm::EventSelfMade_<ContainerAllocator> const> ConstPtr;

}; // struct EventSelfMade_

typedef ::event_comm::EventSelfMade_<std::allocator<void> > EventSelfMade;

typedef boost::shared_ptr< ::event_comm::EventSelfMade > EventSelfMadePtr;
typedef boost::shared_ptr< ::event_comm::EventSelfMade const> EventSelfMadeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::event_comm::EventSelfMade_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::event_comm::EventSelfMade_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace event_comm

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'event_comm': ['/home/cps/catkin_ws_all_0405/src/gml_verify/micro_embedded_collaborative_engine/event_comm/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::event_comm::EventSelfMade_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::event_comm::EventSelfMade_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::event_comm::EventSelfMade_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::event_comm::EventSelfMade_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::event_comm::EventSelfMade_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::event_comm::EventSelfMade_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::event_comm::EventSelfMade_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::event_comm::EventSelfMade_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::event_comm::EventSelfMade_<ContainerAllocator> >
{
  static const char* value()
  {
    return "event_comm/EventSelfMade";
  }

  static const char* value(const ::event_comm::EventSelfMade_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::event_comm::EventSelfMade_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::event_comm::EventSelfMade_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::event_comm::EventSelfMade_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EventSelfMade_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::event_comm::EventSelfMade_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::event_comm::EventSelfMade_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // EVENT_COMM_MESSAGE_EVENTSELFMADE_H
