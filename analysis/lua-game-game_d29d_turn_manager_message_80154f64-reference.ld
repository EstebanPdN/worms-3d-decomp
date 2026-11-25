/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29d_turn_manager_message_80154f64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_worm_80156b24 = 0x80156b24;
advance_80155ff0 = 0x80155ff0;
alloc_801613f0 = 0x801613f0;
base_8016293c = 0x8016293c;
create_8020b680 = 0x8020b680;
create_actor_80156ac4 = 0x80156ac4;
desc_80410940 = 0x80410940;
equals_8015f65c = 0x8015f65c;
get_int_800fc1f0 = 0x800fc1f0;
message_id_8015f5a0 = 0x8015f5a0;
next_team_80155784 = 0x80155784;
post_8016239c = 0x8016239c;
property_write_800fc43c = 0x800fc43c;
publish_alliance_count_80155b44 = 0x80155b44;
publish_team_count_80155688 = 0x80155688;
publish_team_worm_count_80155574 = 0x80155574;
publish_turn_change_80155e24 = 0x80155e24;
publish_worm_count_801555f8 = 0x801555f8;
record_position_8015896c = 0x8015896c;
release_movement_80158b4c = 0x80158b4c;
remove_active_801554dc = 0x801554dc;
remove_current_80155ba4 = 0x80155ba4;
reset_with_message_80156190 = 0x80156190;
retain_movement_80158af0 = 0x80158af0;
select_enemy_80158bb0 = 0x80158bb0;
select_near_80158850 = 0x80158850;
select_opponent_801589c8 = 0x801589c8;
select_team_801560d8 = 0x801560d8;
send_80164514 = 0x80164514;
setup_80156ff0 = 0x80156ff0;
shutdown_80156f68 = 0x80156f68;
str_803a27f0 = 0x803a27f0;
str_803a2860 = 0x803a2860;
str_803a2880 = 0x803a2880;
str_803a2894 = 0x803a2894;
str_803a28b8 = 0x803a28b8;
str_803a28e0 = 0x803a28e0;
str_803a28fc = 0x803a28fc;
str_803a2918 = 0x803a2918;
str_803a2930 = 0x803a2930;
str_803a2950 = 0x803a2950;
str_803a2968 = 0x803a2968;
str_803a2984 = 0x803a2984;
str_803a299c = 0x803a299c;
str_803a29a8 = 0x803a29a8;
trace_80154f58 = 0x80154f58;
turn_notify_80157490 = 0x80157490;
turns_reset_80156884 = 0x80156884;
value_800a830c = 0x800a830c;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d29d_turn_manager_message_80154f64 0x80154f64 : { *(.text.d29d_turn_manager_message_80154f64) }
  .sdata 0x804afe40 (NOLOAD) : {
    . = 0x0; cache_804afe40 = .;
    . = 0x8; cache_804afe48 = .;
    . = 0x18; cache_804afe58 = .;
    . = 0x20; cache_804afe60 = .;
    . = 0x28; cache_804afe68 = .;
    . = 0x38; cache_804afe78 = .;
    . = 0x40; cache_804afe80 = .;
    . = 0x58; cache_804afe98 = .;
    . = 0x60; cache_804afea0 = .;
    . = 0x68; cache_804afea8 = .;
    . = 0x70; cache_804afeb0 = .;
    . = 0x80; cache_804afec0 = .;
    . = 0x90; cache_804afed0 = .;
    . = 0xa0; cache_804afee0 = .;
    . = 0xb8; cache_804afef8 = .;
    . = 0xc0; cache_804aff00 = .;
    . = 0xd0; cache_804aff10 = .;
    . = 0xd8; cache_804aff18 = .;
    . = 0xe8; cache_804aff28 = .;
    . = 0xf0; cache_804aff30 = .;
    . = 0xf8; cache_804aff38 = .;
    . = 0x100; cache_804aff40 = .;
    . = 0x128; cache_804aff68 = .;
    . = 0x130; cache_804aff70 = .;
    . = 0x138; cache_804aff78 = .;
    . = 0x140; cache_804aff80 = .;
    . = 0x1914; heap_804b1754 = .;
    . = 0x194c; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
