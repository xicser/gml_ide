; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventSelfMade.msg.html

(cl:defclass <EventSelfMade> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass EventSelfMade (<EventSelfMade>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventSelfMade>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventSelfMade)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventSelfMade> is deprecated: use event_comm-msg:EventSelfMade instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventSelfMade>) ostream)
  "Serializes a message object of type '<EventSelfMade>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventSelfMade>) istream)
  "Deserializes a message object of type '<EventSelfMade>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventSelfMade>)))
  "Returns string type for a message object of type '<EventSelfMade>"
  "event_comm/EventSelfMade")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventSelfMade)))
  "Returns string type for a message object of type 'EventSelfMade"
  "event_comm/EventSelfMade")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventSelfMade>)))
  "Returns md5sum for a message object of type '<EventSelfMade>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventSelfMade)))
  "Returns md5sum for a message object of type 'EventSelfMade"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventSelfMade>)))
  "Returns full string definition for message of type '<EventSelfMade>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventSelfMade)))
  "Returns full string definition for message of type 'EventSelfMade"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventSelfMade>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventSelfMade>))
  "Converts a ROS message object to a list"
  (cl:list 'EventSelfMade
))
