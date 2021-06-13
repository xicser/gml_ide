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

class EventCollaborative {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.base = null;
      this.collaborativeType = null;
      this.collaborativeEvent = null;
      this.collaborativeObject = null;
    }
    else {
      if (initObj.hasOwnProperty('base')) {
        this.base = initObj.base
      }
      else {
        this.base = new EventBase();
      }
      if (initObj.hasOwnProperty('collaborativeType')) {
        this.collaborativeType = initObj.collaborativeType
      }
      else {
        this.collaborativeType = '';
      }
      if (initObj.hasOwnProperty('collaborativeEvent')) {
        this.collaborativeEvent = initObj.collaborativeEvent
      }
      else {
        this.collaborativeEvent = '';
      }
      if (initObj.hasOwnProperty('collaborativeObject')) {
        this.collaborativeObject = initObj.collaborativeObject
      }
      else {
        this.collaborativeObject = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EventCollaborative
    // Serialize message field [base]
    bufferOffset = EventBase.serialize(obj.base, buffer, bufferOffset);
    // Serialize message field [collaborativeType]
    bufferOffset = _serializer.string(obj.collaborativeType, buffer, bufferOffset);
    // Serialize message field [collaborativeEvent]
    bufferOffset = _serializer.string(obj.collaborativeEvent, buffer, bufferOffset);
    // Serialize message field [collaborativeObject]
    bufferOffset = _arraySerializer.string(obj.collaborativeObject, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EventCollaborative
    let len;
    let data = new EventCollaborative(null);
    // Deserialize message field [base]
    data.base = EventBase.deserialize(buffer, bufferOffset);
    // Deserialize message field [collaborativeType]
    data.collaborativeType = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [collaborativeEvent]
    data.collaborativeEvent = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [collaborativeObject]
    data.collaborativeObject = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += EventBase.getMessageSize(object.base);
    length += object.collaborativeType.length;
    length += object.collaborativeEvent.length;
    object.collaborativeObject.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'event_comm/EventCollaborative';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd067c2bef3be9d576d17bc244d1ee209';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    event_comm/EventBase base
    string collaborativeType
    string collaborativeEvent
    string[] collaborativeObject
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
    const resolved = new EventCollaborative(null);
    if (msg.base !== undefined) {
      resolved.base = EventBase.Resolve(msg.base)
    }
    else {
      resolved.base = new EventBase()
    }

    if (msg.collaborativeType !== undefined) {
      resolved.collaborativeType = msg.collaborativeType;
    }
    else {
      resolved.collaborativeType = ''
    }

    if (msg.collaborativeEvent !== undefined) {
      resolved.collaborativeEvent = msg.collaborativeEvent;
    }
    else {
      resolved.collaborativeEvent = ''
    }

    if (msg.collaborativeObject !== undefined) {
      resolved.collaborativeObject = msg.collaborativeObject;
    }
    else {
      resolved.collaborativeObject = []
    }

    return resolved;
    }
};

module.exports = EventCollaborative;
