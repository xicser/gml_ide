; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventHeartBeat.msg.html

(cl:defclass <EventHeartBeat> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass EventHeartBeat (<EventHeartBeat>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventHeartBeat>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventHeartBeat)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventHeartBeat> is deprecated: use event_comm-msg:EventHeartBeat instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventHeartBeat>) ostream)
  "Serializes a message object of type '<EventHeartBeat>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventHeartBeat>) istream)
  "Deserializes a message object of type '<EventHeartBeat>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventHeartBeat>)))
  "Returns string type for a message object of type '<EventHeartBeat>"
  "event_comm/EventHeartBeat")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventHeartBeat)))
  "Returns string type for a message object of type 'EventHeartBeat"
  "event_comm/EventHeartBeat")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventHeartBeat>)))
  "Returns md5sum for a message object of type '<EventHeartBeat>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventHeartBeat)))
  "Returns md5sum for a message object of type 'EventHeartBeat"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventHeartBeat>)))
  "Returns full string definition for message of type '<EventHeartBeat>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventHeartBeat)))
  "Returns full string definition for message of type 'EventHeartBeat"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventHeartBeat>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventHeartBeat>))
  "Converts a ROS message object to a list"
  (cl:list 'EventHeartBeat
))
