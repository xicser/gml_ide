
(cl:in-package :asdf)

(defsystem "event_comm-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "EventAbnormal" :depends-on ("_package_EventAbnormal"))
    (:file "_package_EventAbnormal" :depends-on ("_package"))
    (:file "EventBase" :depends-on ("_package_EventBase"))
    (:file "_package_EventBase" :depends-on ("_package"))
    (:file "EventCollaborative" :depends-on ("_package_EventCollaborative"))
    (:file "_package_EventCollaborative" :depends-on ("_package"))
    (:file "EventDynamic" :depends-on ("_package_EventDynamic"))
    (:file "_package_EventDynamic" :depends-on ("_package"))
    (:file "EventHeartBeat" :depends-on ("_package_EventHeartBeat"))
    (:file "_package_EventHeartBeat" :depends-on ("_package"))
    (:file "EventSelfMade" :depends-on ("_package_EventSelfMade"))
    (:file "_package_EventSelfMade" :depends-on ("_package"))
    (:file "UAVState" :depends-on ("_package_UAVState"))
    (:file "_package_UAVState" :depends-on ("_package"))
  ))