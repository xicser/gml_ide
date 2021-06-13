
(cl:in-package :asdf)

(defsystem "event_syn-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "EventBase" :depends-on ("_package_EventBase"))
    (:file "_package_EventBase" :depends-on ("_package"))
    (:file "EventSynergy" :depends-on ("_package_EventSynergy"))
    (:file "_package_EventSynergy" :depends-on ("_package"))
  ))