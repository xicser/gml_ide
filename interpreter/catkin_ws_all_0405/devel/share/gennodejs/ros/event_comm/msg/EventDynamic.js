// Auto-generated. Do not edit!

// (in-package event_comm.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EventBase = require('./EventBase.js');

//-----------------------------------------------------------

class EventDynamic {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.base = null;
      this.dynamicEventName = null;
      this.dynamicType = null;
      this.dynamicInfo = null;
    }
    else {
      if (initObj.hasOwnProperty('base')) {
        this.base = initObj.base
      }
      else {
        this.base = new EventBase();
      }
      if (initObj.hasOwnProperty('dynamicEventName')) {
        this.dynamicEventName = initObj.dynamicEventName
      }
      else {
        this.dynamicEventName = '';
      }
      if (initObj.hasOwnProperty('dynamicType')) {
        this.dynamicType = initObj.dynamicType
      }
      else {
        this.dynamicType = '';
      }
      if (initObj.hasOwnProperty('dynamicInfo')) {
        this.dynamicInfo = initObj.dynamicInfo
      }
      else {
        this.dynamicInfo = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EventDynamic
    // Serialize message field [base]
    bufferOffset = EventBase.serialize(obj.base, buffer, bufferOffset);
    // Serialize message field [dynamicEventName]
    bufferOffset = _serializer.string(obj.dynamicEventName, buffer, bufferOffset);
    // Serialize message field [dynamicType]
    bufferOffset = _serializer.string(obj.dynamicType, buffer, bufferOffset);
    // Serialize message field [dynamicInfo]
    bufferOffset = _serializer.string(obj.dynamicInfo, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EventDynamic
    let len;
    let data = new EventDynamic(null);
    // Deserialize message field [base]
    data.base = EventBase.deserialize(buffer, bufferOffset);
    // Deserialize message field [dynamicEventName]
    data.dynamicEventName = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [dynamicType]
    data.dynamicType = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [dynamicInfo]
    data.dynamicInfo = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += EventBase.getMessageSize(object.base);
    length += object.dynamicEventName.length;
    length += object.dynamicType.length;
    length += object.dynamicInfo.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'event_comm/EventDynamic';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2ccc20968a7c0d24ca90b858f3122b4b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    event_comm/EventBase base
    string dynamicEventName
    string dynamicType
    string dynamicInfo
    ================================================================================
    MSG: event_comm/EventBase
    std_msgs/Header header
    string eventID
    string source
    time begintime
    time endtime
    geometry_msgs/Point startPoint
    geometry_msgs/Point endPoint
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
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EventDynamic(null);
    if (msg.base !== undefined) {
      resolved.base = EventBase.Resolve(msg.base)
    }
    else {
      resolved.base = new EventBase()
    }

    if (msg.dynamicEventName !== undefined) {
      resolved.dynamicEventName = msg.dynamicEventName;
    }
    else {
      resolved.dynamicEventName = ''
    }

    if (msg.dynamicType !== undefined) {
      resolved.dynamicType = msg.dynamicType;
    }
    else {
      resolved.dynamicType = ''
    }

    if (msg.dynamicInfo !== undefined) {
      resolved.dynamicInfo = msg.dynamicInfo;
    }
    else {
      resolved.dynamicInfo = ''
    }

    return resolved;
    }
};

module.exports = EventDynamic;
