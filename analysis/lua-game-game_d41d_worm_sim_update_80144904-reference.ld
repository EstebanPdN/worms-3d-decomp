/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41d_worm_sim_update_80144904)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
air_8014f8cc = 0x8014f8cc;
air_move_80146190 = 0x80146190;
air_step_8014e9ec = 0x8014e9ec;
alloc_801613f0 = 0x801613f0;
b3b4_8014b3b4 = 0x8014b3b4;
b40c_8014b40c = 0x8014b40c;
b84_80146b84 = 0x80146b84;
behaviour_801515a4 = 0x801515a4;
bob_8014e170 = 0x8014e170;
c001_803a0f94 = 0x803a0f94;
c100_803a0f98 = 0x803a0f98;
cast_80342a74 = 0x80342a74;
cast_80342a78 = 0x80342a78;
coll_8014c7fc = 0x8014c7fc;
contact_801418c4 = 0x801418c4;
db4_80153db4 = 0x80153db4;
dc04_8014dc04 = 0x8014dc04;
dc60_8014dc60 = 0x8014dc60;
dcbc_8014dcbc = 0x8014dcbc;
de70_8014de70 = 0x8014de70;
death_8014cb88 = 0x8014cb88;
df28_8014df28 = 0x8014df28;
dir_80146f10 = 0x80146f10;
drown_80149f18 = 0x80149f18;
e104_8014e104 = 0x8014e104;
e3d4_8014e3d4 = 0x8014e3d4;
e44c_8014e44c = 0x8014e44c;
empty_8014fd34 = 0x8014fd34;
engine_80165254 = 0x80165254;
f34_80146f34 = 0x80146f34;
fd1c_8015fd1c = 0x8015fd1c;
file_803a0e2c = 0x803a0e2c;
follow_8014dd18 = 0x8014dd18;
fwd_800e5ca4 = 0x800e5ca4;
fwd_800fdd80 = 0x800fdd80;
g_80020b20 = 0x80020b20;
h_801510c4 = 0x801510c4;
has_motion_8014c3f4 = 0x8014c3f4;
item_800fc710 = 0x800fc710;
jet_8014d7c8 = 0x8014d7c8;
jump_8014ae84 = 0x8014ae84;
land_8014b498 = 0x8014b498;
linkb_8014decc = 0x8014decc;
m025_803a0f90 = 0x803a0f90;
message_id_8015f5a0 = 0x8015f5a0;
mode_8012f964 = 0x8012f964;
msg_init_800a82f0 = 0x800a82f0;
near_8014d59c = 0x8014d59c;
notify_800fde64 = 0x800fde64;
notify_800fdf24 = 0x800fdf24;
ok_8014c488 = 0x8014c488;
post_8016239c = 0x8016239c;
query_800fc6dc = 0x800fc6dc;
r_8015286c = 0x8015286c;
read_800fc330 = 0x800fc330;
rot_8014fb40 = 0x8014fb40;
s_803a089c = 0x803a089c;
s_803a0ed0 = 0x803a0ed0;
s_803a0ef8 = 0x803a0ef8;
s_803a0f14 = 0x803a0f14;
s_803a0f28 = 0x803a0f28;
s_803a0f40 = 0x803a0f40;
s_803a0f50 = 0x803a0f50;
s_803a0f68 = 0x803a0f68;
scene_8006e71c = 0x8006e71c;
send_to_8015fc58 = 0x8015fc58;
set_801492ec = 0x801492ec;
spot_8014a9f8 = 0x8014a9f8;
sqrtf_802e82c0 = 0x802e82c0;
step_801502f0 = 0x801502f0;
stop_80150018 = 0x80150018;
target_8015324c = 0x8015324c;
trace_80022e20 = 0x80022e20;
track_8014da00 = 0x8014da00;
turn_8014b6b0 = 0x8014b6b0;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
update_80178d28 = 0x80178d28;
value_80178df0 = 0x80178df0;
vt_8040db38 = 0x8040db38;
walk_8014a510 = 0x8014a510;
yaw_8015139c = 0x8015139c;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d41d_worm_sim_update_80144904 0x80144904 : { *(.text.w3d_d41d_worm_sim_update_80144904) }
  .rodata 0x803a0f7c : { *(.rodata) }
  .sdata 0x804aafac (NOLOAD) : {
    . = 0x0; limit_804aafac = .;
    . = 0x438; last_804ab3e4 = .;
    . = 0x4bc4; cache_804afb70 = .;
    . = 0x4bd4; cache_804afb80 = .;
    . = 0x4d5c; cache_804afd08 = .;
    . = 0x4d9c; cache_804afd48 = .;
    . = 0x4da4; cache_804afd50 = .;
    . = 0x67a8; heap_804b1754 = .;
    . = 0x67b4; global_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
