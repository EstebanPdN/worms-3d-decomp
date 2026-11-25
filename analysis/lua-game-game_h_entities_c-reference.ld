/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_wind_meter_entity_list_get_8012fed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_base_initialize = 0x80161014;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_destroy_8015fa94 = 0x8015fa94;
w3d_base_destroy_801628ec = 0x801628ec;
w3d_base_handle_message_8015fb34 = 0x8015fb34;
w3d_entity_list_803617d0 = 0x803617d0;
w3d_entity_vtable_804115c8 = 0x804115c8;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_input_service_construct_8016030c = 0x8016030c;
w3d_input_service_list_80361830 = 0x80361830;
w3d_input_service_vtable_804116a8 = 0x804116a8;
w3d_logic_entity_list_80361860 = 0x80361860;
w3d_message_registration_service_construct_8016169c = 0x8016169c;
w3d_message_registration_service_destroy_80161ae0 = 0x80161ae0;
w3d_message_registration_service_list_803618c0 = 0x803618c0;
w3d_owner_list_remove = 0x8020fd2c;
w3d_service_construct_801628b0 = 0x801628b0;
w3d_service_list_803618f0 = 0x803618f0;
w3d_service_vtable_80411828 = 0x80411828;
w3d_state_register = 0x8020fd04;
w3d_telnet_service_construct_8015b084 = 0x8015b084;
w3d_telnet_service_destroy_8015b0c4 = 0x8015b0c4;
w3d_telnet_service_list_80361680 = 0x80361680;
w3d_timer_service_construct_801653ac = 0x801653ac;
w3d_timer_service_list_80361980 = 0x80361980;
w3d_timer_service_vtable_80411970 = 0x80411970;
w3d_wind_meter_entity_construct_8012fff4 = 0x8012fff4;
w3d_wind_meter_entity_list_80361560 = 0x80361560;
w3d_wind_meter_entity_vtable_80410e40 = 0x80410e40;
w3d_worm_graphic_entity_construct_80131d44 = 0x80131d44;
w3d_worm_graphic_entity_destroy_801320c8 = 0x801320c8;
w3d_worm_graphic_entity_list_80361590 = 0x80361590;
w3d_worm_health_name_entity_construct_80140940 = 0x80140940;
w3d_worm_health_name_entity_list_803615c0 = 0x803615c0;
w3d_worm_health_name_entity_vtable_80410ec0 = 0x80410ec0;
w3d_worm_manager_service_construct_80154918 = 0x80154918;
w3d_worm_manager_service_destroy_80154aa8 = 0x80154aa8;
w3d_worm_manager_service_list_80454118 = 0x80454118;
w3d_worm_select_logic_entity_construct_801594bc = 0x801594bc;
w3d_worm_select_logic_entity_destroy_80159538 = 0x80159538;
w3d_worm_select_logic_entity_list_80361620 = 0x80361620;
w3d_zcam_update_fudge_service_attach_8015a040 = 0x8015a040;
w3d_zcam_update_fudge_service_construct_80159ef8 = 0x80159ef8;
w3d_zcam_update_fudge_service_detach_8015a044 = 0x8015a044;
w3d_zcam_update_fudge_service_list_80361650 = 0x80361650;
w3d_zcam_update_fudge_service_vtable_80410fc0 = 0x80410fc0;
SECTIONS {
  .text.w3d_wind_meter_entity_list_get_8012fed0 0x8012fed0 : { *(.text.w3d_wind_meter_entity_list_get_8012fed0) }
  .text.w3d_wind_meter_entity_unlink_8012fedc 0x8012fedc : { *(.text.w3d_wind_meter_entity_unlink_8012fedc) }
  .text.w3d_wind_meter_entity_create_8012ff20 0x8012ff20 : { *(.text.w3d_wind_meter_entity_create_8012ff20) }
  .text.w3d_wind_meter_entity_release_8012ff80 0x8012ff80 : { *(.text.w3d_wind_meter_entity_release_8012ff80) }
  .text.w3d_wind_meter_entity_retain_8012ffdc 0x8012ffdc : { *(.text.w3d_wind_meter_entity_retain_8012ffdc) }
  .text.w3d_wind_meter_entity_destroy_801300c8 0x801300c8 : { *(.text.w3d_wind_meter_entity_destroy_801300c8) }
  .text.w3d_worm_graphic_entity_list_get_80131c20 0x80131c20 : { *(.text.w3d_worm_graphic_entity_list_get_80131c20) }
  .text.w3d_worm_graphic_entity_unlink_80131c2c 0x80131c2c : { *(.text.w3d_worm_graphic_entity_unlink_80131c2c) }
  .text.w3d_worm_graphic_entity_create_80131c70 0x80131c70 : { *(.text.w3d_worm_graphic_entity_create_80131c70) }
  .text.w3d_worm_graphic_entity_release_80131cd0 0x80131cd0 : { *(.text.w3d_worm_graphic_entity_release_80131cd0) }
  .text.w3d_worm_graphic_entity_retain_80131d2c 0x80131d2c : { *(.text.w3d_worm_graphic_entity_retain_80131d2c) }
  .text.w3d_worm_health_name_entity_list_get_8014081c 0x8014081c : { *(.text.w3d_worm_health_name_entity_list_get_8014081c) }
  .text.w3d_worm_health_name_entity_unlink_80140828 0x80140828 : { *(.text.w3d_worm_health_name_entity_unlink_80140828) }
  .text.w3d_worm_health_name_entity_create_8014086c 0x8014086c : { *(.text.w3d_worm_health_name_entity_create_8014086c) }
  .text.w3d_worm_health_name_entity_release_801408cc 0x801408cc : { *(.text.w3d_worm_health_name_entity_release_801408cc) }
  .text.w3d_worm_health_name_entity_retain_80140928 0x80140928 : { *(.text.w3d_worm_health_name_entity_retain_80140928) }
  .text.w3d_worm_health_name_entity_destroy_80140998 0x80140998 : { *(.text.w3d_worm_health_name_entity_destroy_80140998) }
  .text.w3d_worm_manager_service_list_get_801547f4 0x801547f4 : { *(.text.w3d_worm_manager_service_list_get_801547f4) }
  .text.w3d_worm_manager_service_unlink_80154800 0x80154800 : { *(.text.w3d_worm_manager_service_unlink_80154800) }
  .text.w3d_worm_manager_service_create_80154844 0x80154844 : { *(.text.w3d_worm_manager_service_create_80154844) }
  .text.w3d_worm_manager_service_release_801548a4 0x801548a4 : { *(.text.w3d_worm_manager_service_release_801548a4) }
  .text.w3d_worm_manager_service_retain_80154900 0x80154900 : { *(.text.w3d_worm_manager_service_retain_80154900) }
  .text.w3d_worm_select_logic_entity_list_get_80159398 0x80159398 : { *(.text.w3d_worm_select_logic_entity_list_get_80159398) }
  .text.w3d_worm_select_logic_entity_unlink_801593a4 0x801593a4 : { *(.text.w3d_worm_select_logic_entity_unlink_801593a4) }
  .text.w3d_worm_select_logic_entity_create_801593e8 0x801593e8 : { *(.text.w3d_worm_select_logic_entity_create_801593e8) }
  .text.w3d_worm_select_logic_entity_release_80159448 0x80159448 : { *(.text.w3d_worm_select_logic_entity_release_80159448) }
  .text.w3d_worm_select_logic_entity_retain_801594a4 0x801594a4 : { *(.text.w3d_worm_select_logic_entity_retain_801594a4) }
  .text.w3d_zcam_update_fudge_service_list_get_80159dd4 0x80159dd4 : { *(.text.w3d_zcam_update_fudge_service_list_get_80159dd4) }
  .text.w3d_zcam_update_fudge_service_unlink_80159de0 0x80159de0 : { *(.text.w3d_zcam_update_fudge_service_unlink_80159de0) }
  .text.w3d_zcam_update_fudge_service_create_80159e24 0x80159e24 : { *(.text.w3d_zcam_update_fudge_service_create_80159e24) }
  .text.w3d_zcam_update_fudge_service_release_80159e84 0x80159e84 : { *(.text.w3d_zcam_update_fudge_service_release_80159e84) }
  .text.w3d_zcam_update_fudge_service_retain_80159ee0 0x80159ee0 : { *(.text.w3d_zcam_update_fudge_service_retain_80159ee0) }
  .text.w3d_zcam_update_fudge_service_destroy_80159f34 0x80159f34 : { *(.text.w3d_zcam_update_fudge_service_destroy_80159f34) }
  .text.w3d_zcam_update_fudge_service_handle_message_80159f64 0x80159f64 : { *(.text.w3d_zcam_update_fudge_service_handle_message_80159f64) }
  .text.w3d_telnet_service_list_get_8015af60 0x8015af60 : { *(.text.w3d_telnet_service_list_get_8015af60) }
  .text.w3d_telnet_service_unlink_8015af6c 0x8015af6c : { *(.text.w3d_telnet_service_unlink_8015af6c) }
  .text.w3d_telnet_service_create_8015afb0 0x8015afb0 : { *(.text.w3d_telnet_service_create_8015afb0) }
  .text.w3d_telnet_service_release_8015b010 0x8015b010 : { *(.text.w3d_telnet_service_release_8015b010) }
  .text.w3d_telnet_service_retain_8015b06c 0x8015b06c : { *(.text.w3d_telnet_service_retain_8015b06c) }
  .text.w3d_entity_list_get_8015fdcc 0x8015fdcc : { *(.text.w3d_entity_list_get_8015fdcc) }
  .text.w3d_entity_unlink_8015fdd8 0x8015fdd8 : { *(.text.w3d_entity_unlink_8015fdd8) }
  .text.w3d_entity_create_8015fe1c 0x8015fe1c : { *(.text.w3d_entity_create_8015fe1c) }
  .text.w3d_entity_release_8015fe7c 0x8015fe7c : { *(.text.w3d_entity_release_8015fe7c) }
  .text.w3d_entity_retain_8015fed8 0x8015fed8 : { *(.text.w3d_entity_retain_8015fed8) }
  .text.w3d_base_destroy_8015ff2c 0x8015ff2c : { *(.text.w3d_base_destroy_8015ff2c) }
  .text.w3d_input_service_list_get_801601e8 0x801601e8 : { *(.text.w3d_input_service_list_get_801601e8) }
  .text.w3d_input_service_unlink_801601f4 0x801601f4 : { *(.text.w3d_input_service_unlink_801601f4) }
  .text.w3d_input_service_create_80160238 0x80160238 : { *(.text.w3d_input_service_create_80160238) }
  .text.w3d_input_service_release_80160298 0x80160298 : { *(.text.w3d_input_service_release_80160298) }
  .text.w3d_input_service_retain_801602f4 0x801602f4 : { *(.text.w3d_input_service_retain_801602f4) }
  .text.w3d_input_service_destroy_80160388 0x80160388 : { *(.text.w3d_input_service_destroy_80160388) }
  .text.w3d_logic_entity_list_get_80160ef0 0x80160ef0 : { *(.text.w3d_logic_entity_list_get_80160ef0) }
  .text.w3d_logic_entity_unlink_80160efc 0x80160efc : { *(.text.w3d_logic_entity_unlink_80160efc) }
  .text.w3d_logic_entity_create_80160f40 0x80160f40 : { *(.text.w3d_logic_entity_create_80160f40) }
  .text.w3d_logic_entity_release_80160fa0 0x80160fa0 : { *(.text.w3d_logic_entity_release_80160fa0) }
  .text.w3d_logic_entity_retain_80160ffc 0x80160ffc : { *(.text.w3d_logic_entity_retain_80160ffc) }
  .text.w3d_message_registration_service_list_get_8016144c 0x8016144c : { *(.text.w3d_message_registration_service_list_get_8016144c) }
  .text.w3d_message_registration_service_unlink_80161458 0x80161458 : { *(.text.w3d_message_registration_service_unlink_80161458) }
  .text.w3d_message_registration_service_create_8016149c 0x8016149c : { *(.text.w3d_message_registration_service_create_8016149c) }
  .text.w3d_message_registration_service_release_801614fc 0x801614fc : { *(.text.w3d_message_registration_service_release_801614fc) }
  .text.w3d_message_registration_service_retain_80161558 0x80161558 : { *(.text.w3d_message_registration_service_retain_80161558) }
  .text.w3d_service_list_get_8016278c 0x8016278c : { *(.text.w3d_service_list_get_8016278c) }
  .text.w3d_service_unlink_80162798 0x80162798 : { *(.text.w3d_service_unlink_80162798) }
  .text.w3d_service_create_801627dc 0x801627dc : { *(.text.w3d_service_create_801627dc) }
  .text.w3d_service_release_8016283c 0x8016283c : { *(.text.w3d_service_release_8016283c) }
  .text.w3d_service_retain_80162898 0x80162898 : { *(.text.w3d_service_retain_80162898) }
  .text.w3d_service_destroy_801628ec 0x801628ec : { *(.text.w3d_service_destroy_801628ec) }
  .text.w3d_timer_service_list_get_80165288 0x80165288 : { *(.text.w3d_timer_service_list_get_80165288) }
  .text.w3d_timer_service_unlink_80165294 0x80165294 : { *(.text.w3d_timer_service_unlink_80165294) }
  .text.w3d_timer_service_create_801652d8 0x801652d8 : { *(.text.w3d_timer_service_create_801652d8) }
  .text.w3d_timer_service_release_80165338 0x80165338 : { *(.text.w3d_timer_service_release_80165338) }
  .text.w3d_timer_service_retain_80165394 0x80165394 : { *(.text.w3d_timer_service_retain_80165394) }
  .text.w3d_timer_service_destroy_801653f0 0x801653f0 : { *(.text.w3d_timer_service_destroy_801653f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
