QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += qt
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += network
QT +=sql

CONFIG += qt thread
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/3dparty/mavlink_v2
INCLUDEPATH += $$PWD/3dparty/mavlink_v2ardupilotmega
SOURCES += \
    abstract_communicator_factory.cpp \
    abstract_handler.cpp \
    abstract_link.cpp \
    ack_handler.cpp \
    attitude_handler.cpp \
    battery_handler.cpp \
    commands_sender.cpp \
    gcs_communicator_factory.cpp \
    gps_handler.cpp \
    heartbeat_handler.cpp \
    info_abstract_handler.cpp \
    info_communicator.cpp \
    info_message_handler.cpp \
    log_handler.cpp \
    main.cpp \
    mainwindow.cpp \
    mavlink_communicator.cpp \
    sql_communicator.cpp \
    status_handler.cpp \
    udp_link.cpp

HEADERS += \
    3dparty/mavlink_v2/ASLUAV/ASLUAV.h \
    3dparty/mavlink_v2/ASLUAV/mavlink.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_asl_obctrl.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_aslctrl_data.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_aslctrl_debug.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_asluav_status.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_command_int_stamped.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_command_long_stamped.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_ekf_ext.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_fw_soaring_data.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_gsm_link_status.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sens_atmos.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sens_batmon.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sens_mppt.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sens_power.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sens_power_board.h \
    3dparty/mavlink_v2/ASLUAV/mavlink_msg_sensorpod_status.h \
    3dparty/mavlink_v2/ASLUAV/testsuite.h \
    3dparty/mavlink_v2/ASLUAV/version.h \
    3dparty/mavlink_v2/ardupilotmega/ardupilotmega.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_adap_tuning.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_ahrs.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_ahrs2.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_ahrs3.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_airspeed_autocal.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_aoa_ssa.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_ap_adc.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_autopilot_version_request.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_battery2.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_camera_feedback.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_camera_status.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_compassmot_status.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_data16.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_data32.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_data64.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_data96.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_deepstall.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_device_op_read.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_device_op_read_reply.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_device_op_write.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_device_op_write_reply.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_digicam_configure.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_digicam_control.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_ekf_status_report.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_esc_telemetry_1_to_4.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_esc_telemetry_5_to_8.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_esc_telemetry_9_to_12.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_fence_fetch_point.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_fence_point.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gimbal_control.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gimbal_report.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gimbal_torque_cmd_report.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gopro_get_request.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gopro_get_response.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gopro_heartbeat.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gopro_set_request.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_gopro_set_response.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_hwstatus.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_led_control.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_limits_status.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_mag_cal_progress.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_meminfo.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_mount_configure.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_mount_control.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_mount_status.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_pid_tuning.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_radio.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_rally_fetch_point.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_rally_point.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_rangefinder.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_remote_log_block_status.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_remote_log_data_block.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_rpm.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_sensor_offsets.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_set_mag_offsets.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_simstate.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_vision_position_delta.h \
    3dparty/mavlink_v2/ardupilotmega/mavlink_msg_wind.h \
    3dparty/mavlink_v2/ardupilotmega/testsuite.h \
    3dparty/mavlink_v2/ardupilotmega/version.h \
    3dparty/mavlink_v2/autoquad/autoquad.h \
    3dparty/mavlink_v2/autoquad/mavlink.h \
    3dparty/mavlink_v2/autoquad/mavlink_msg_aq_esc_telemetry.h \
    3dparty/mavlink_v2/autoquad/mavlink_msg_aq_telemetry_f.h \
    3dparty/mavlink_v2/autoquad/testsuite.h \
    3dparty/mavlink_v2/autoquad/version.h \
    3dparty/mavlink_v2/checksum.h \
    3dparty/mavlink_v2/common/common.h \
    3dparty/mavlink_v2/common/mavlink.h \
    3dparty/mavlink_v2/common/mavlink_msg_actuator_control_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_actuator_output_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_adsb_vehicle.h \
    3dparty/mavlink_v2/common/mavlink_msg_ais_vessel.h \
    3dparty/mavlink_v2/common/mavlink_msg_altitude.h \
    3dparty/mavlink_v2/common/mavlink_msg_att_pos_mocap.h \
    3dparty/mavlink_v2/common/mavlink_msg_attitude.h \
    3dparty/mavlink_v2/common/mavlink_msg_attitude_quaternion.h \
    3dparty/mavlink_v2/common/mavlink_msg_attitude_quaternion_cov.h \
    3dparty/mavlink_v2/common/mavlink_msg_attitude_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_auth_key.h \
    3dparty/mavlink_v2/common/mavlink_msg_autopilot_state_for_gimbal_device.h \
    3dparty/mavlink_v2/common/mavlink_msg_autopilot_version.h \
    3dparty/mavlink_v2/common/mavlink_msg_battery_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_button_change.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_capture_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_fov_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_image_captured.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_settings.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_tracking_geo_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_tracking_image_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_camera_trigger.h \
    3dparty/mavlink_v2/common/mavlink_msg_cellular_config.h \
    3dparty/mavlink_v2/common/mavlink_msg_cellular_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_change_operator_control.h \
    3dparty/mavlink_v2/common/mavlink_msg_change_operator_control_ack.h \
    3dparty/mavlink_v2/common/mavlink_msg_collision.h \
    3dparty/mavlink_v2/common/mavlink_msg_command_ack.h \
    3dparty/mavlink_v2/common/mavlink_msg_command_cancel.h \
    3dparty/mavlink_v2/common/mavlink_msg_command_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_command_long.h \
    3dparty/mavlink_v2/common/mavlink_msg_component_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_control_system_state.h \
    3dparty/mavlink_v2/common/mavlink_msg_data_stream.h \
    3dparty/mavlink_v2/common/mavlink_msg_data_transmission_handshake.h \
    3dparty/mavlink_v2/common/mavlink_msg_debug.h \
    3dparty/mavlink_v2/common/mavlink_msg_debug_float_array.h \
    3dparty/mavlink_v2/common/mavlink_msg_debug_vect.h \
    3dparty/mavlink_v2/common/mavlink_msg_distance_sensor.h \
    3dparty/mavlink_v2/common/mavlink_msg_efi_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_encapsulated_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_esc_info.h \
    3dparty/mavlink_v2/common/mavlink_msg_esc_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_estimator_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_extended_sys_state.h \
    3dparty/mavlink_v2/common/mavlink_msg_fence_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_file_transfer_protocol.h \
    3dparty/mavlink_v2/common/mavlink_msg_flight_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_follow_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_generator_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_device_attitude_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_device_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_device_set_attitude.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_manager_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_manager_set_attitude.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_manager_set_tiltpan.h \
    3dparty/mavlink_v2/common/mavlink_msg_gimbal_manager_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_global_position_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_global_position_int_cov.h \
    3dparty/mavlink_v2/common/mavlink_msg_global_vision_position_estimate.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps2_raw.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps2_rtk.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_global_origin.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_inject_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_input.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_raw_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_rtcm_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_rtk.h \
    3dparty/mavlink_v2/common/mavlink_msg_gps_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_high_latency.h \
    3dparty/mavlink_v2/common/mavlink_msg_high_latency2.h \
    3dparty/mavlink_v2/common/mavlink_msg_highres_imu.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_actuator_controls.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_controls.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_gps.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_optical_flow.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_rc_inputs_raw.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_sensor.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_state.h \
    3dparty/mavlink_v2/common/mavlink_msg_hil_state_quaternion.h \
    3dparty/mavlink_v2/common/mavlink_msg_home_position.h \
    3dparty/mavlink_v2/common/mavlink_msg_isbd_link_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_landing_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_link_node_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_local_position_ned.h \
    3dparty/mavlink_v2/common/mavlink_msg_local_position_ned_cov.h \
    3dparty/mavlink_v2/common/mavlink_msg_local_position_ned_system_global_offset.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_entry.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_erase.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_request_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_request_end.h \
    3dparty/mavlink_v2/common/mavlink_msg_log_request_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_logging_ack.h \
    3dparty/mavlink_v2/common/mavlink_msg_logging_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_logging_data_acked.h \
    3dparty/mavlink_v2/common/mavlink_msg_mag_cal_report.h \
    3dparty/mavlink_v2/common/mavlink_msg_manual_control.h \
    3dparty/mavlink_v2/common/mavlink_msg_manual_setpoint.h \
    3dparty/mavlink_v2/common/mavlink_msg_memory_vect.h \
    3dparty/mavlink_v2/common/mavlink_msg_message_interval.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_ack.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_changed.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_clear_all.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_count.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_current.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_item.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_item_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_item_reached.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_request.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_request_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_request_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_request_partial_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_set_current.h \
    3dparty/mavlink_v2/common/mavlink_msg_mission_write_partial_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_mount_orientation.h \
    3dparty/mavlink_v2/common/mavlink_msg_named_value_float.h \
    3dparty/mavlink_v2/common/mavlink_msg_named_value_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_nav_controller_output.h \
    3dparty/mavlink_v2/common/mavlink_msg_obstacle_distance.h \
    3dparty/mavlink_v2/common/mavlink_msg_odometry.h \
    3dparty/mavlink_v2/common/mavlink_msg_onboard_computer_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_authentication.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_basic_id.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_location.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_message_pack.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_operator_id.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_self_id.h \
    3dparty/mavlink_v2/common/mavlink_msg_open_drone_id_system.h \
    3dparty/mavlink_v2/common/mavlink_msg_optical_flow.h \
    3dparty/mavlink_v2/common/mavlink_msg_optical_flow_rad.h \
    3dparty/mavlink_v2/common/mavlink_msg_orbit_execution_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ack_transaction.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_ack.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_ack_trimmed.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_request_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_request_read.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_set.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_set_trimmed.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_value.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_ext_value_trimmed.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_map_rc.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_request_list.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_request_read.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_set.h \
    3dparty/mavlink_v2/common/mavlink_msg_param_value.h \
    3dparty/mavlink_v2/common/mavlink_msg_ping.h \
    3dparty/mavlink_v2/common/mavlink_msg_play_tune.h \
    3dparty/mavlink_v2/common/mavlink_msg_play_tune_v2.h \
    3dparty/mavlink_v2/common/mavlink_msg_position_target_global_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_position_target_local_ned.h \
    3dparty/mavlink_v2/common/mavlink_msg_power_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_radio_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_raw_imu.h \
    3dparty/mavlink_v2/common/mavlink_msg_raw_pressure.h \
    3dparty/mavlink_v2/common/mavlink_msg_raw_rpm.h \
    3dparty/mavlink_v2/common/mavlink_msg_rc_channels.h \
    3dparty/mavlink_v2/common/mavlink_msg_rc_channels_override.h \
    3dparty/mavlink_v2/common/mavlink_msg_rc_channels_raw.h \
    3dparty/mavlink_v2/common/mavlink_msg_rc_channels_scaled.h \
    3dparty/mavlink_v2/common/mavlink_msg_request_data_stream.h \
    3dparty/mavlink_v2/common/mavlink_msg_resource_request.h \
    3dparty/mavlink_v2/common/mavlink_msg_safety_allowed_area.h \
    3dparty/mavlink_v2/common/mavlink_msg_safety_set_allowed_area.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_imu.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_imu2.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_imu3.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_pressure.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_pressure2.h \
    3dparty/mavlink_v2/common/mavlink_msg_scaled_pressure3.h \
    3dparty/mavlink_v2/common/mavlink_msg_serial_control.h \
    3dparty/mavlink_v2/common/mavlink_msg_servo_output_raw.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_actuator_control_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_attitude_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_gps_global_origin.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_home_position.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_mode.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_position_target_global_int.h \
    3dparty/mavlink_v2/common/mavlink_msg_set_position_target_local_ned.h \
    3dparty/mavlink_v2/common/mavlink_msg_setup_signing.h \
    3dparty/mavlink_v2/common/mavlink_msg_sim_state.h \
    3dparty/mavlink_v2/common/mavlink_msg_smart_battery_info.h \
    3dparty/mavlink_v2/common/mavlink_msg_smart_battery_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_statustext.h \
    3dparty/mavlink_v2/common/mavlink_msg_storage_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_supported_tunes.h \
    3dparty/mavlink_v2/common/mavlink_msg_sys_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_system_time.h \
    3dparty/mavlink_v2/common/mavlink_msg_terrain_check.h \
    3dparty/mavlink_v2/common/mavlink_msg_terrain_data.h \
    3dparty/mavlink_v2/common/mavlink_msg_terrain_report.h \
    3dparty/mavlink_v2/common/mavlink_msg_terrain_request.h \
    3dparty/mavlink_v2/common/mavlink_msg_time_estimate_to_target.h \
    3dparty/mavlink_v2/common/mavlink_msg_timesync.h \
    3dparty/mavlink_v2/common/mavlink_msg_trajectory_representation_bezier.h \
    3dparty/mavlink_v2/common/mavlink_msg_trajectory_representation_waypoints.h \
    3dparty/mavlink_v2/common/mavlink_msg_tunnel.h \
    3dparty/mavlink_v2/common/mavlink_msg_uavcan_node_info.h \
    3dparty/mavlink_v2/common/mavlink_msg_uavcan_node_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_utm_global_position.h \
    3dparty/mavlink_v2/common/mavlink_msg_v2_extension.h \
    3dparty/mavlink_v2/common/mavlink_msg_vfr_hud.h \
    3dparty/mavlink_v2/common/mavlink_msg_vibration.h \
    3dparty/mavlink_v2/common/mavlink_msg_vicon_position_estimate.h \
    3dparty/mavlink_v2/common/mavlink_msg_video_stream_information.h \
    3dparty/mavlink_v2/common/mavlink_msg_video_stream_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_vision_position_estimate.h \
    3dparty/mavlink_v2/common/mavlink_msg_vision_speed_estimate.h \
    3dparty/mavlink_v2/common/mavlink_msg_wheel_distance.h \
    3dparty/mavlink_v2/common/mavlink_msg_wifi_config_ap.h \
    3dparty/mavlink_v2/common/mavlink_msg_winch_status.h \
    3dparty/mavlink_v2/common/mavlink_msg_wind_cov.h \
    3dparty/mavlink_v2/common/testsuite.h \
    3dparty/mavlink_v2/common/version.h \
    3dparty/mavlink_v2/icarous/icarous.h \
    3dparty/mavlink_v2/icarous/mavlink.h \
    3dparty/mavlink_v2/icarous/mavlink_msg_icarous_heartbeat.h \
    3dparty/mavlink_v2/icarous/mavlink_msg_icarous_kinematic_bands.h \
    3dparty/mavlink_v2/icarous/testsuite.h \
    3dparty/mavlink_v2/icarous/version.h \
    3dparty/mavlink_v2/matrixpilot/matrixpilot.h \
    3dparty/mavlink_v2/matrixpilot/mavlink.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_airspeeds.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_altitudes.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_buffer_function.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_buffer_function_ack.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_command.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_command_ack.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_directory.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_directory_ack.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_read_req.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_flexifunction_set.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f13.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f14.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f15.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f16.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f17.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f18.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f19.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f20.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f21.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f22.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f2_a.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f2_b.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f4.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f5.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f6.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f7.h \
    3dparty/mavlink_v2/matrixpilot/mavlink_msg_serial_udb_extra_f8.h \
    3dparty/mavlink_v2/matrixpilot/testsuite.h \
    3dparty/mavlink_v2/matrixpilot/version.h \
    3dparty/mavlink_v2/mavlink_conversions.h \
    3dparty/mavlink_v2/mavlink_get_info.h \
    3dparty/mavlink_v2/mavlink_helpers.h \
    3dparty/mavlink_v2/mavlink_sha256.h \
    3dparty/mavlink_v2/mavlink_types.h \
    3dparty/mavlink_v2/minimal/mavlink.h \
    3dparty/mavlink_v2/minimal/mavlink_msg_heartbeat.h \
    3dparty/mavlink_v2/minimal/mavlink_msg_protocol_version.h \
    3dparty/mavlink_v2/minimal/minimal.h \
    3dparty/mavlink_v2/minimal/testsuite.h \
    3dparty/mavlink_v2/minimal/version.h \
    3dparty/mavlink_v2/protocol.h \
    3dparty/mavlink_v2/standard/mavlink.h \
    3dparty/mavlink_v2/standard/standard.h \
    3dparty/mavlink_v2/standard/testsuite.h \
    3dparty/mavlink_v2/standard/version.h \
    3dparty/mavlink_v2/test/mavlink.h \
    3dparty/mavlink_v2/test/mavlink_msg_test_types.h \
    3dparty/mavlink_v2/test/test.h \
    3dparty/mavlink_v2/test/testsuite.h \
    3dparty/mavlink_v2/test/version.h \
    3dparty/mavlink_v2/uAvionix/mavlink.h \
    3dparty/mavlink_v2/uAvionix/mavlink_msg_uavionix_adsb_out_cfg.h \
    3dparty/mavlink_v2/uAvionix/mavlink_msg_uavionix_adsb_out_dynamic.h \
    3dparty/mavlink_v2/uAvionix/mavlink_msg_uavionix_adsb_transceiver_health_report.h \
    3dparty/mavlink_v2/uAvionix/testsuite.h \
    3dparty/mavlink_v2/uAvionix/uAvionix.h \
    3dparty/mavlink_v2/uAvionix/version.h \
    abstract_communicator_factory.h \
    abstract_handler.h \
    abstract_link.h \
    ack_handler.h \
    attitude_handler.h \
    battery_handler.h \
    commands_sender.h \
    gcs_communicator_factory.h \
    gps_handler.h \
    heartbeat_handler.h \
    info_abstract_handler.h \
    info_communicator.h \
    info_message_handler.h \
    log_handler.h \
    mainwindow.h \
    mavlink_communicator.h \
    sql_communicator.h \
    status_handler.h \
    udp_link.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    3dparty/mavlink_v2/message_definitions/ASLUAV.xml \
    3dparty/mavlink_v2/message_definitions/all.xml \
    3dparty/mavlink_v2/message_definitions/ardupilotmega.xml \
    3dparty/mavlink_v2/message_definitions/autoquad.xml \
    3dparty/mavlink_v2/message_definitions/common.xml \
    3dparty/mavlink_v2/message_definitions/icarous.xml \
    3dparty/mavlink_v2/message_definitions/matrixpilot.xml \
    3dparty/mavlink_v2/message_definitions/minimal.xml \
    3dparty/mavlink_v2/message_definitions/paparazzi.xml \
    3dparty/mavlink_v2/message_definitions/python_array_test.xml \
    3dparty/mavlink_v2/message_definitions/standard.xml \
    3dparty/mavlink_v2/message_definitions/test.xml \
    3dparty/mavlink_v2/message_definitions/uAvionix.xml \
    3dparty/mavlink_v2/message_definitions/ualberta.xml

