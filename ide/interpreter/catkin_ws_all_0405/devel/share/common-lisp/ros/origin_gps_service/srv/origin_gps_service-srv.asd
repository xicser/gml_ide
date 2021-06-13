
(cl:in-package :asdf)

(defsystem "origin_gps_service-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "SetGetOriginGPS" :depends-on ("_package_SetGetOriginGPS"))
    (:file "_package_SetGetOriginGPS" :depends-on ("_package"))
  ))