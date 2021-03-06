# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from event_syn/EventSynergy.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import event_syn.msg
import genpy
import geometry_msgs.msg

class EventSynergy(genpy.Message):
  _md5sum = "8a522657f44ca2b2a7a97cab253c1c6b"
  _type = "event_syn/EventSynergy"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """event_syn/EventBase base
string synergyType
string synergyEvent
string[] synergyObject
================================================================================
MSG: event_syn/EventBase
int64 ID
string source
time begintime
time endtime
geometry_msgs/Point startPoint
geometry_msgs/Point endPoint
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['base','synergyType','synergyEvent','synergyObject']
  _slot_types = ['event_syn/EventBase','string','string','string[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       base,synergyType,synergyEvent,synergyObject

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(EventSynergy, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.base is None:
        self.base = event_syn.msg.EventBase()
      if self.synergyType is None:
        self.synergyType = ''
      if self.synergyEvent is None:
        self.synergyEvent = ''
      if self.synergyObject is None:
        self.synergyObject = []
    else:
      self.base = event_syn.msg.EventBase()
      self.synergyType = ''
      self.synergyEvent = ''
      self.synergyObject = []

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
      _x = self.base.ID
      buff.write(_get_struct_q().pack(_x))
      _x = self.base.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_4I6d().pack(_x.base.begintime.secs, _x.base.begintime.nsecs, _x.base.endtime.secs, _x.base.endtime.nsecs, _x.base.startPoint.x, _x.base.startPoint.y, _x.base.startPoint.z, _x.base.endPoint.x, _x.base.endPoint.y, _x.base.endPoint.z))
      _x = self.synergyType
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.synergyEvent
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.synergyObject)
      buff.write(_struct_I.pack(length))
      for val1 in self.synergyObject:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.Struct('<I%ss'%length).pack(length, val1))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.base is None:
        self.base = event_syn.msg.EventBase()
      end = 0
      start = end
      end += 8
      (self.base.ID,) = _get_struct_q().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.base.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.base.source = str[start:end]
      _x = self
      start = end
      end += 64
      (_x.base.begintime.secs, _x.base.begintime.nsecs, _x.base.endtime.secs, _x.base.endtime.nsecs, _x.base.startPoint.x, _x.base.startPoint.y, _x.base.startPoint.z, _x.base.endPoint.x, _x.base.endPoint.y, _x.base.endPoint.z,) = _get_struct_4I6d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.synergyType = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.synergyType = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.synergyEvent = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.synergyEvent = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.synergyObject = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1 = str[start:end]
        self.synergyObject.append(val1)
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
      _x = self.base.ID
      buff.write(_get_struct_q().pack(_x))
      _x = self.base.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_4I6d().pack(_x.base.begintime.secs, _x.base.begintime.nsecs, _x.base.endtime.secs, _x.base.endtime.nsecs, _x.base.startPoint.x, _x.base.startPoint.y, _x.base.startPoint.z, _x.base.endPoint.x, _x.base.endPoint.y, _x.base.endPoint.z))
      _x = self.synergyType
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.synergyEvent
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.synergyObject)
      buff.write(_struct_I.pack(length))
      for val1 in self.synergyObject:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.Struct('<I%ss'%length).pack(length, val1))
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
      if self.base is None:
        self.base = event_syn.msg.EventBase()
      end = 0
      start = end
      end += 8
      (self.base.ID,) = _get_struct_q().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.base.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.base.source = str[start:end]
      _x = self
      start = end
      end += 64
      (_x.base.begintime.secs, _x.base.begintime.nsecs, _x.base.endtime.secs, _x.base.endtime.nsecs, _x.base.startPoint.x, _x.base.startPoint.y, _x.base.startPoint.z, _x.base.endPoint.x, _x.base.endPoint.y, _x.base.endPoint.z,) = _get_struct_4I6d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.synergyType = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.synergyType = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.synergyEvent = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.synergyEvent = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.synergyObject = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1 = str[start:end]
        self.synergyObject.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4I6d = None
def _get_struct_4I6d():
    global _struct_4I6d
    if _struct_4I6d is None:
        _struct_4I6d = struct.Struct("<4I6d")
    return _struct_4I6d
_struct_q = None
def _get_struct_q():
    global _struct_q
    if _struct_q is None:
        _struct_q = struct.Struct("<q")
    return _struct_q
