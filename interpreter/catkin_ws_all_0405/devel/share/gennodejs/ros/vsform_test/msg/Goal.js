// Auto-generated. Do not edit!

// (in-package vsform_test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class Goal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.frame_pos = null;
      this.frame_vel = null;
      this.path_width = null;
    }
    else {
      if (initObj.hasOwnProperty('frame_pos')) {
        this.frame_pos = initObj.frame_pos
      }
      else {
        this.frame_pos = new geometry_msgs.msg.Point32();
      }
      if (initObj.hasOwnProperty('frame_vel')) {
        this.frame_vel = initObj.frame_vel
      }
      else {
        this.frame_vel = new geometry_msgs.msg.Point32();
      }
      if (initObj.hasOwnProperty('path_width')) {
        this.path_width = initObj.path_width
      }
      else {
        this.path_width = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Goal
    // Serialize message field [frame_pos]
    bufferOffset = geometry_msgs.msg.Point32.serialize(obj.frame_pos, buffer, bufferOffset);
    // Serialize message field [frame_vel]
    bufferOffset = geometry_msgs.msg.Point32.serialize(obj.frame_vel, buffer, bufferOffset);
    // Serialize message field [path_width]
    bufferOffset = _serializer.float32(obj.path_width, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Goal
    let len;
    let data = new Goal(null);
    // Deserialize message field [frame_pos]
    data.frame_pos = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset);
    // Deserialize message field [frame_vel]
    data.frame_vel = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset);
    // Deserialize message field [path_width]
    data.path_width = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'vsform_test/Goal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b0c8263c41fcbdd38a6148d2ecdf8e38';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point32 frame_pos # frame position
    geometry_msgs/Point32 frame_vel # frame velocity
    float32 path_width # path width
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Goal(null);
    if (msg.frame_pos !== undefined) {
      resolved.frame_pos = geometry_msgs.msg.Point32.Resolve(msg.frame_pos)
    }
    else {
      resolved.frame_pos = new geometry_msgs.msg.Point32()
    }

    if (msg.frame_vel !== undefined) {
      resolved.frame_vel = geometry_msgs.msg.Point32.Resolve(msg.frame_vel)
    }
    else {
      resolved.frame_vel = new geometry_msgs.msg.Point32()
    }

    if (msg.path_width !== undefined) {
      resolved.path_width = msg.path_width;
    }
    else {
      resolved.path_width = 0.0
    }

    return resolved;
    }
};

module.exports = Goal;
