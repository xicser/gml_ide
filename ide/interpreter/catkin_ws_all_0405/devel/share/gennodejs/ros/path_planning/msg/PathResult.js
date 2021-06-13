// Auto-generated. Do not edit!

// (in-package path_planning.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class PathResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PathResult
    // Serialize message field [result]
    // Serialize the length for message field [result]
    bufferOffset = _serializer.uint32(obj.result.length, buffer, bufferOffset);
    obj.result.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PathResult
    let len;
    let data = new PathResult(null);
    // Deserialize message field [result]
    // Deserialize array length for message field [result]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.result = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.result[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 24 * object.result.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'path_planning/PathResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5ac55cb602cab21c0a526eb965fe531a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point[] result
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
    const resolved = new PathResult(null);
    if (msg.result !== undefined) {
      resolved.result = new Array(msg.result.length);
      for (let i = 0; i < resolved.result.length; ++i) {
        resolved.result[i] = geometry_msgs.msg.Point.Resolve(msg.result[i]);
      }
    }
    else {
      resolved.result = []
    }

    return resolved;
    }
};

module.exports = PathResult;
