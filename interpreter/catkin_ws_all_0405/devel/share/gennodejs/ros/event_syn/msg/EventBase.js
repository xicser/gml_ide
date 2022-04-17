// Auto-generated. Do not edit!

// (in-package event_syn.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class EventBase {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ID = null;
      this.source = null;
      this.begintime = null;
      this.endtime = null;
      this.startPoint = null;
      this.endPoint = null;
    }
    else {
      if (initObj.hasOwnProperty('ID')) {
        this.ID = initObj.ID
      }
      else {
        this.ID = 0;
      }
      if (initObj.hasOwnProperty('source')) {
        this.source = initObj.source
      }
      else {
        this.source = '';
      }
      if (initObj.hasOwnProperty('begintime')) {
        this.begintime = initObj.begintime
      }
      else {
        this.begintime = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('endtime')) {
        this.endtime = initObj.endtime
      }
      else {
        this.endtime = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('startPoint')) {
        this.startPoint = initObj.startPoint
      }
      else {
        this.startPoint = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('endPoint')) {
        this.endPoint = initObj.endPoint
      }
      else {
        this.endPoint = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EventBase
    // Serialize message field [ID]
    bufferOffset = _serializer.int64(obj.ID, buffer, bufferOffset);
    // Serialize message field [source]
    bufferOffset = _serializer.string(obj.source, buffer, bufferOffset);
    // Serialize message field [begintime]
    bufferOffset = _serializer.time(obj.begintime, buffer, bufferOffset);
    // Serialize message field [endtime]
    bufferOffset = _serializer.time(obj.endtime, buffer, bufferOffset);
    // Serialize message field [startPoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.startPoint, buffer, bufferOffset);
    // Serialize message field [endPoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.endPoint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EventBase
    let len;
    let data = new EventBase(null);
    // Deserialize message field [ID]
    data.ID = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [source]
    data.source = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [begintime]
    data.begintime = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [endtime]
    data.endtime = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [startPoint]
    data.startPoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [endPoint]
    data.endPoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.source.length;
    return length + 76;
  }

  static datatype() {
    // Returns string type for a message object
    return 'event_syn/EventBase';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0fd9c6075ee389ae992199348b844526';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EventBase(null);
    if (msg.ID !== undefined) {
      resolved.ID = msg.ID;
    }
    else {
      resolved.ID = 0
    }

    if (msg.source !== undefined) {
      resolved.source = msg.source;
    }
    else {
      resolved.source = ''
    }

    if (msg.begintime !== undefined) {
      resolved.begintime = msg.begintime;
    }
    else {
      resolved.begintime = {secs: 0, nsecs: 0}
    }

    if (msg.endtime !== undefined) {
      resolved.endtime = msg.endtime;
    }
    else {
      resolved.endtime = {secs: 0, nsecs: 0}
    }

    if (msg.startPoint !== undefined) {
      resolved.startPoint = geometry_msgs.msg.Point.Resolve(msg.startPoint)
    }
    else {
      resolved.startPoint = new geometry_msgs.msg.Point()
    }

    if (msg.endPoint !== undefined) {
      resolved.endPoint = geometry_msgs.msg.Point.Resolve(msg.endPoint)
    }
    else {
      resolved.endPoint = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = EventBase;
