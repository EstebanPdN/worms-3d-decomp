/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_camera_bob_8014e170)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
check_80146b84 = 0x80146b84;
clear_msg_801040d0 = 0x801040d0;
coll_a_80141574 = 0x80141574;
coll_b_8014156c = 0x8014156c;
coll_count_80141554 = 0x80141554;
contact_801418c4 = 0x801418c4;
landing_8014b498 = 0x8014b498;
limit_8014c89c = 0x8014c89c;
msgid_8015f5a0 = 0x8015f5a0;
mvt_8040db38 = 0x8040db38;
pair_8005200c = 0x8005200c;
post_8016239c = 0x8016239c;
res_80178d1c = 0x80178d1c;
setting_800fc270 = 0x800fc270;
w3d_cx9c_cosf_802e86d4 = 0x802e86d4;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d25d_worm_camera_bob_8014e170 0x8014e170 : { *(.text.d25d_worm_camera_bob_8014e170) }
  .rodata 0x803a1694 : { *(.rodata) }
  .sdata 0x804aaa10 (NOLOAD) : {
    . = 0x0; cam_804aaa10 = .;
    . = 0x9dc; phase_804ab3ec = .;
    . = 0x5200; idcache_804afc10 = .;
    . = 0x6d44; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
