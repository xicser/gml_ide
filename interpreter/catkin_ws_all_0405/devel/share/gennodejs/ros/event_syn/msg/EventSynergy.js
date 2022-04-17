// Auto-generated. Do not edit!

// (in-package event_syn.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EventBase = require('./EventBase.js');

//-----------------------------------------------------------

class EventSynergy {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.base = null;
      this.synergyType = null;
      this.synergyEvent = null;
      this.synergyObject = null;
    }
    else {
      if (initObj.hasOwnProperty('base')) {
        this.base = initObj.base
      }
      else {
        this.base = new EventBase();
      }
      if (initObj.hasOwnProperty('synergyType')) {
        this.synergyType = initObj.synergyType
      }
      else {
        this.synergyType = '';
      }
      if (initObj.hasOwnProperty('synergyEvent')) {
        this.synergyEvent = initObj.synergyEvent
      }
      else {
        this.synergyEvent = '';
      }
      if (initObj.hasOwnProperty('synergyObject')) {
        this.synergyObject = initObj.synergyObject
      }
      else {
        this.synergyObject = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EventSynergy
    // Serialize message field [base]
    bufferOffset = EventBase.serialize(obj.base, buffer, bufferOffset);
    // Serialize message field [synergyType]
    bufferOffset = _serializer.string(obj.synergyType, buffer, bufferOffset);
    // Serialize message field [synergyEvent]
    bufferOffset = _serializer.string(obj.synergyEvent, buffer, bufferOffset);
    // Serialize message field [synergyObject]
    bufferOffset = _arraySerializer.string(obj.synergyObject, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EventSynergy
    let len;
    let data = new EventSynergy(null);
    // Deserialize message field [base]
    data.base = EventBase.deserialize(buffer, bufferOffset);
    // Deserialize message field [synergyType]
    data.synergyType = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [synergyEvent]
    data.synergyEvent = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [synergyObject]
    data.synergyObject = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += EventBase.getMessageSize(object.base);
    length += object.synergyType.length;
    length += object.synergyEvent.length;
    object.synergyObject.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'event_syn/EventSynergy';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8a522657f44ca2b2a7a97cab253c1c6b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    event_syn/EventBase base
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EventSynergy(null);
    if (msg.base !== undefined) {
      resolved.base = EventBase.Resolve(msg.base)
    }
    else {
      resolved.base = new EventBase()
    }

    if (msg.synergyType !== undefined) {
      resolved.synergyType = msg.synergyType;
    }
    else {
      resolved.synergyType = ''
    }

    if (msg.synergyEvent !== undefined) {
      resolved.synergyEvent = msg.synergyEvent;
    }
    else {
      resolved.synergyEvent = ''
    }

    if (msg.synergyObject !== undefined) {
      resolved.synergyObject = msg.synergyObject;
    }
    else {
      resolved.synergyObject = []
    }

    return resolved;
    }
};

module.exports = EventSynergy;
