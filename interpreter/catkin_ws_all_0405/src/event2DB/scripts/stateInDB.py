#!/usr/bin/env python3
# -*- coding:utf-8 -*-


import pymysql
import rospy
import time
from event_comm.msg import UAVState


table_suffix = None


def init():
    db = pymysql.connect("localhost", "root", "mysql123",
                         "micro_embedded_engine")
    cursor = db.cursor()
    CREATE_SQL = """CREATE TABLE IF NOT EXISTS `states%s` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UAVnum` int(11) DEFAULT NULL,
  `x` float DEFAULT 0.0,
  `y` float DEFAULT 0.0,
  `z` float DEFAULT 0.0,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
""" % table_suffix
    cursor.execute(CREATE_SQL)
    db.commit()

    print("Table created successfully")

    filename = 'state.txt'
    with open(filename, 'w') as file_object:
        file_object.write(table_suffix)

    db.close()


def get_table_suffix():
    return time.strftime("%Y%m%d%H%M", time.localtime())


def insert_data(data):
    print(data)
    conn = pymysql.connect("localhost", "root", "mysql123",
                         "micro_embedded_engine")
    # INSERT_SQL = """ insert into "events%s" (seq,stamp,eventID,source,begintime,endtime,eventType,eventName,contentType,contentInfo) values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""" % table_suffix
    INSERT_SQL = """ insert into states%s (UAVnum,x,y,z) values('%s', '%s', '%s', '%s')""" % (table_suffix,*data)
    print(INSERT_SQL)
    c = conn.cursor()
    # c.execute(INSERT_SQL, data)
    c.execute(INSERT_SQL)
    conn.commit()
    conn.close()
    print("Insert successfully")


# def event_syn_callback(msg):
#     # print(type(msg.synergyObject))
#     temp = ','.join(msg.synergyObject) if isinstance(msg.synergyObject,list) else msg.synergyObject
#     data = (msg.base.ID, msg.base.begintime.to_sec(), msg.base.ID, msg.base.source, msg.base.begintime.to_sec(),
#             msg.base.endtime.to_sec(), "Collaborative", msg.synergyEvent, msg.synergyType, temp)
#     insert_data(data)


def uav_state_callback(msg):
    data = (msg.UAVnum, msg.Point.x,msg.Point.y,msg.Point.z)
    insert_data(data)


def save_states():
    global table_suffix
    table_suffix = get_table_suffix()
    print("table_suffix:", table_suffix)
    init()
    print('init databse ok')
    rospy.init_node('save_uav_states', anonymous=True)
    rospy.Subscriber('/uav_state', UAVState, uav_state_callback)
    rospy.spin()


if __name__ == "__main__":
    try:
        save_states()
    except rospy.ROSInterruptException:
        pass
