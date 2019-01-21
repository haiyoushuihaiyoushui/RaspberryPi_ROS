;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorials::Active)
  (if (not (find-package "BEGINNER_TUTORIALS"))
    (make-package "BEGINNER_TUTORIALS"))
  (shadow 'Active (find-package "BEGINNER_TUTORIALS")))
(unless (find-package "BEGINNER_TUTORIALS::ACTIVE")
  (make-package "BEGINNER_TUTORIALS::ACTIVE"))

(in-package "ROS")
;;//! \htmlinclude Active.msg.html


(defclass beginner_tutorials::Active
  :super ros::object
  :slots (_direction _speed ))

(defmethod beginner_tutorials::Active
  (:init
   (&key
    ((:direction __direction) 0)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _direction (round __direction))
   (setq _speed (float __speed))
   self)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; int8 _direction
    1
    ;; float32 _speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _direction
       (write-byte _direction s)
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _direction
     (setq _direction (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _direction 127) (setq _direction (- _direction 256)))
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get beginner_tutorials::Active :md5sum-) "303d95c789e3846c8cef0567c921b988")
(setf (get beginner_tutorials::Active :datatype-) "beginner_tutorials/Active")
(setf (get beginner_tutorials::Active :definition-)
      "int8 direction
float32 speed

")



(provide :beginner_tutorials/Active "303d95c789e3846c8cef0567c921b988")


