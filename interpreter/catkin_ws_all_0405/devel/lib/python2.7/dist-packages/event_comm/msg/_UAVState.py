# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from event_comm/UAVState.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class UAVState(genpy.Message):
  _md5sum = "82010c98432e82a612d456b09f37f399"
  _type = "event_comm/UAVState"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint64 UAVnum
geometry_msgs/Point Point
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['UAVnum','Point']
  _slot_types = ['uint64','geometry_msgs/Point']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       UAVnum,Point

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(UAVState, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.UAVnum is None:
        self.UAVnum = 0
      if self.Point is None:
        self.Point = geometry_msgs.msg.Point()
    else:
      self.UAVnum = 0
      self.Point = geometry_msgs.msg.Point()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_Q3d().pack(_x.UAVnum, _x.Point.x, _x.Point.y, _x.Point.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.Point is None:
        self.Point = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.UAVnum, _x.Point.x, _x.Point.y, _x.Point.z,) = _get_struct_Q3d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_Q3d().pack(_x.UAVnum, _x.Point.x, _x.Point.y, _x.Point.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.Point is None:
        self.Point = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.UAVnum, _x.Point.x, _x.Point.y, _x.Point.z,) = _get_struct_Q3d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_Q3d = None
def _get_struct_Q3d():
    global _struct_Q3d
    if _struct_Q3d is None:
        _struct_Q3d = struct.Struct("<Q3d")
    return _struct_Q3d
