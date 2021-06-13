// Auto-generated. Do not edit!

// (in-package event_comm.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class UAVState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.UAVnum = null;
      this.Point = null;
    }
    else {
      if (initObj.hasOwnProperty('UAVnum')) {
        this.UAVnum = initObj.UAVnum
      }
      else {
        this.UAVnum = 0;
      }
      if (initObj.hasOwnProperty('Point')) {
        this.Point = initObj.Point
      }
      else {
        this.Point = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UAVState
    // Serialize message field [UAVnum]
    bufferOffset = _serializer.uint64(obj.UAVnum, buffer, bufferOffset);
    // Serialize message field [Point]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.Point, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UAVState
    let len;
    let data = new UAVState(null);
    // Deserialize message field [UAVnum]
    data.UAVnum = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [Point]
    data.Point = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'event_comm/UAVState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '82010c98432e82a612d456b09f37f399';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint64 UAVnum
    geometry_msgs/Point Point
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
    const resolved = new UAVState(null);
    if (msg.UAVnum !== undefined) {
      resolved.UAVnum = msg.UAVnum;
    }
    else {
      resolved.UAVnum = 0
    }

    if (msg.Point !== undefined) {
      resolved.Point = geometry_msgs.msg.Point.Resolve(msg.Point)
    }
    else {
      resolved.Point = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = UAVState;
