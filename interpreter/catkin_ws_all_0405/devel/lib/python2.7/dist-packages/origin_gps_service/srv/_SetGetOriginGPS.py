# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from origin_gps_service/SetGetOriginGPSRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import sensor_msgs.msg
import std_msgs.msg

class SetGetOriginGPSRequest(genpy.Message):
  _md5sum = "4c0259f305cb1466733443da33383005"
  _type = "origin_gps_service/SetGetOriginGPSRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """sensor_msgs/NavSatFix home_gps

================================================================================
MSG: sensor_msgs/NavSatFix
# Navigation Satellite fix for any Global Navigation Satellite System
#
# Specified using the WGS 84 reference ellipsoid

# header.stamp specifies the ROS time for this measurement (the
#        corresponding satellite time may be reported using the
#        sensor_msgs/TimeReference message).
#
# header.frame_id is the frame of reference reported by the satellite
#        receiver, usually the location of the antenna.  This is a
#        Euclidean frame relative to the vehicle, not a reference
#        ellipsoid.
Header header

# satellite fix status information
NavSatStatus status

# Latitude [degrees]. Positive is north of equator; negative is south.
float64 latitude

# Longitude [degrees]. Positive is east of prime meridian; negative is west.
float64 longitude

# Altitude [m]. Positive is above the WGS 84 ellipsoid
# (quiet NaN if no altitude is available).
float64 altitude

# Position covariance [m^2] defined relative to a tangential plane
# through the reported position. The components are East, North, and
# Up (ENU), in row-major order.
#
# Beware: this coordinate system exhibits singularities at the poles.

float64[9] position_covariance

# If the covariance of the fix is known, fill it in completely. If the
# GPS receiver provides the variance of each measurement, put them
# along the diagonal. If only Dilution of Precision is available,
# estimate an approximate covariance from that.

uint8 COVARIANCE_TYPE_UNKNOWN = 0
uint8 COVARIANCE_TYPE_APPROXIMATED = 1
uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2
uint8 COVARIANCE_TYPE_KNOWN = 3

uint8 position_covariance_type

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: sensor_msgs/NavSatStatus
# Navigation Satellite fix status for any Global Navigation Satellite System

# Whether to output an augmented fix is determined by both the fix
# type and the last time differential corrections were received.  A
# fix is valid when status >= STATUS_FIX.

int8 STATUS_NO_FIX =  -1        # unable to fix position
int8 STATUS_FIX =      0        # unaugmented fix
int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation
int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation

int8 status

# Bits defining which Global Navigation Satellite System signals were
# used by the receiver.

uint16 SERVICE_GPS =     1
uint16 SERVICE_GLONASS = 2
uint16 SERVICE_COMPASS = 4      # includes BeiDou.
uint16 SERVICE_GALILEO = 8

uint16 service
"""
  __slots__ = ['home_gps']
  _slot_types = ['sensor_msgs/NavSatFix']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       home_gps

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SetGetOriginGPSRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.home_gps is None:
        self.home_gps = sensor_msgs.msg.NavSatFix()
    else:
      self.home_gps = sensor_msgs.msg.NavSatFix()

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
      buff.write(_get_struct_3I().pack(_x.home_gps.header.seq, _x.home_gps.header.stamp.secs, _x.home_gps.header.stamp.nsecs))
      _x = self.home_gps.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_bH3d().pack(_x.home_gps.status.status, _x.home_gps.status.service, _x.home_gps.latitude, _x.home_gps.longitude, _x.home_gps.altitude))
      buff.write(_get_struct_9d().pack(*self.home_gps.position_covariance))
      _x = self.home_gps.position_covariance_type
      buff.write(_get_struct_B().pack(_x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.home_gps is None:
        self.home_gps = sensor_msgs.msg.NavSatFix()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.home_gps.header.seq, _x.home_gps.header.stamp.secs, _x.home_gps.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.home_gps.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.home_gps.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 27
      (_x.home_gps.status.status, _x.home_gps.status.service, _x.home_gps.latitude, _x.home_gps.longitude, _x.home_gps.altitude,) = _get_struct_bH3d().unpack(str[start:end])
      start = end
      end += 72
      self.home_gps.position_covariance = _get_struct_9d().unpack(str[start:end])
      start = end
      end += 1
      (self.home_gps.position_covariance_type,) = _get_struct_B().unpack(str[start:end])
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
      buff.write(_get_struct_3I().pack(_x.home_gps.header.seq, _x.home_gps.header.stamp.secs, _x.home_gps.header.stamp.nsecs))
      _x = self.home_gps.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_bH3d().pack(_x.home_gps.status.status, _x.home_gps.status.service, _x.home_gps.latitude, _x.home_gps.longitude, _x.home_gps.altitude))
      buff.write(self.home_gps.position_covariance.tostring())
      _x = self.home_gps.position_covariance_type
      buff.write(_get_struct_B().pack(_x))
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
      if self.home_gps is None:
        self.home_gps = sensor_msgs.msg.NavSatFix()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.home_gps.header.seq, _x.home_gps.header.stamp.secs, _x.home_gps.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.home_gps.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.home_gps.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 27
      (_x.home_gps.status.status, _x.home_gps.status.service, _x.home_gps.latitude, _x.home_gps.longitude, _x.home_gps.altitude,) = _get_struct_bH3d().unpack(str[start:end])
      start = end
      end += 72
      self.home_gps.position_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=9)
      start = end
      end += 1
      (self.home_gps.position_covariance_type,) = _get_struct_B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_9d = None
def _get_struct_9d():
    global _struct_9d
    if _struct_9d is None:
        _struct_9d = struct.Struct("<9d")
    return _struct_9d
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_bH3d = None
def _get_struct_bH3d():
    global _struct_bH3d
    if _struct_bH3d is None:
        _struct_bH3d = struct.Struct("<bH3d")
    return _struct_bH3d
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from origin_gps_service/SetGetOriginGPSResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import sensor_msgs.msg
import std_msgs.msg

class SetGetOriginGPSResponse(genpy.Message):
  _md5sum = "ba304f5c76d1ea2bcc4e2d2385aa4968"
  _type = "origin_gps_service/SetGetOriginGPSResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """sensor_msgs/NavSatFix origin_gps

================================================================================
MSG: sensor_msgs/NavSatFix
# Navigation Satellite fix for any Global Navigation Satellite System
#
# Specified using the WGS 84 reference ellipsoid

# header.stamp specifies the ROS time for this measurement (the
#        corresponding satellite time may be reported using the
#        sensor_msgs/TimeReference message).
#
# header.frame_id is the frame of reference reported by the satellite
#        receiver, usually the location of the antenna.  This is a
#        Euclidean frame relative to the vehicle, not a reference
#        ellipsoid.
Header header

# satellite fix status information
NavSatStatus status

# Latitude [degrees]. Positive is north of equator; negative is south.
float64 latitude

# Longitude [degrees]. Positive is east of prime meridian; negative is west.
float64 longitude

# Altitude [m]. Positive is above the WGS 84 ellipsoid
# (quiet NaN if no altitude is available).
float64 altitude

# Position covariance [m^2] defined relative to a tangential plane
# through the reported position. The components are East, North, and
# Up (ENU), in row-major order.
#
# Beware: this coordinate system exhibits singularities at the poles.

float64[9] position_covariance

# If the covariance of the fix is known, fill it in completely. If the
# GPS receiver provides the variance of each measurement, put them
# along the diagonal. If only Dilution of Precision is available,
# estimate an approximate covariance from that.

uint8 COVARIANCE_TYPE_UNKNOWN = 0
uint8 COVARIANCE_TYPE_APPROXIMATED = 1
uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2
uint8 COVARIANCE_TYPE_KNOWN = 3

uint8 position_covariance_type

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: sensor_msgs/NavSatStatus
# Navigation Satellite fix status for any Global Navigation Satellite System

# Whether to output an augmented fix is determined by both the fix
# type and the last time differential corrections were received.  A
# fix is valid when status >= STATUS_FIX.

int8 STATUS_NO_FIX =  -1        # unable to fix position
int8 STATUS_FIX =      0        # unaugmented fix
int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation
int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation

int8 status

# Bits defining which Global Navigation Satellite System signals were
# used by the receiver.

uint16 SERVICE_GPS =     1
uint16 SERVICE_GLONASS = 2
uint16 SERVICE_COMPASS = 4      # includes BeiDou.
uint16 SERVICE_GALILEO = 8

uint16 service
"""
  __slots__ = ['origin_gps']
  _slot_types = ['sensor_msgs/NavSatFix']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       origin_gps

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SetGetOriginGPSResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.origin_gps is None:
        self.origin_gps = sensor_msgs.msg.NavSatFix()
    else:
      self.origin_gps = sensor_msgs.msg.NavSatFix()

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
      buff.write(_get_struct_3I().pack(_x.origin_gps.header.seq, _x.origin_gps.header.stamp.secs, _x.origin_gps.header.stamp.nsecs))
      _x = self.origin_gps.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_bH3d().pack(_x.origin_gps.status.status, _x.origin_gps.status.service, _x.origin_gps.latitude, _x.origin_gps.longitude, _x.origin_gps.altitude))
      buff.write(_get_struct_9d().pack(*self.origin_gps.position_covariance))
      _x = self.origin_gps.position_covariance_type
      buff.write(_get_struct_B().pack(_x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.origin_gps is None:
        self.origin_gps = sensor_msgs.msg.NavSatFix()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.origin_gps.header.seq, _x.origin_gps.header.stamp.secs, _x.origin_gps.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.origin_gps.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.origin_gps.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 27
      (_x.origin_gps.status.status, _x.origin_gps.status.service, _x.origin_gps.latitude, _x.origin_gps.longitude, _x.origin_gps.altitude,) = _get_struct_bH3d().unpack(str[start:end])
      start = end
      end += 72
      self.origin_gps.position_covariance = _get_struct_9d().unpack(str[start:end])
      start = end
      end += 1
      (self.origin_gps.position_covariance_type,) = _get_struct_B().unpack(str[start:end])
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
      buff.write(_get_struct_3I().pack(_x.origin_gps.header.seq, _x.origin_gps.header.stamp.secs, _x.origin_gps.header.stamp.nsecs))
      _x = self.origin_gps.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_bH3d().pack(_x.origin_gps.status.status, _x.origin_gps.status.service, _x.origin_gps.latitude, _x.origin_gps.longitude, _x.origin_gps.altitude))
      buff.write(self.origin_gps.position_covariance.tostring())
      _x = self.origin_gps.position_covariance_type
      buff.write(_get_struct_B().pack(_x))
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
      if self.origin_gps is None:
        self.origin_gps = sensor_msgs.msg.NavSatFix()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.origin_gps.header.seq, _x.origin_gps.header.stamp.secs, _x.origin_gps.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.origin_gps.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.origin_gps.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 27
      (_x.origin_gps.status.status, _x.origin_gps.status.service, _x.origin_gps.latitude, _x.origin_gps.longitude, _x.origin_gps.altitude,) = _get_struct_bH3d().unpack(str[start:end])
      start = end
      end += 72
      self.origin_gps.position_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=9)
      start = end
      end += 1
      (self.origin_gps.position_covariance_type,) = _get_struct_B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_9d = None
def _get_struct_9d():
    global _struct_9d
    if _struct_9d is None:
        _struct_9d = struct.Struct("<9d")
    return _struct_9d
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_bH3d = None
def _get_struct_bH3d():
    global _struct_bH3d
    if _struct_bH3d is None:
        _struct_bH3d = struct.Struct("<bH3d")
    return _struct_bH3d
class SetGetOriginGPS(object):
  _type          = 'origin_gps_service/SetGetOriginGPS'
  _md5sum = '76078d86916adec6d06d1ecf85305b35'
  _request_class  = SetGetOriginGPSRequest
  _response_class = SetGetOriginGPSResponse