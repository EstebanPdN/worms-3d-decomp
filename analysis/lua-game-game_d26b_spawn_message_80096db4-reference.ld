/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26b_spawn_message_80096db4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_assign_8009afe8 = 0x8009afe8;
w3d_assign_800e8fb4 = 0x800e8fb4;
w3d_class_8040e358 = 0x8040e358;
w3d_class_8040e468 = 0x8040e468;
w3d_class_8040e6c8 = 0x8040e6c8;
w3d_class_8040e748 = 0x8040e748;
w3d_class_8040e968 = 0x8040e968;
w3d_class_8040ee30 = 0x8040ee30;
w3d_class_8040eff0 = 0x8040eff0;
w3d_class_8040f1a8 = 0x8040f1a8;
w3d_class_8040f280 = 0x8040f280;
w3d_class_8040f340 = 0x8040f340;
w3d_class_8040f6e8 = 0x8040f6e8;
w3d_class_8040fbb8 = 0x8040fbb8;
w3d_class_8040fcb8 = 0x8040fcb8;
w3d_class_8040fdf0 = 0x8040fdf0;
w3d_class_80410008 = 0x80410008;
w3d_class_804101a0 = 0x804101a0;
w3d_class_80410b88 = 0x80410b88;
w3d_class_80410e70 = 0x80410e70;
w3d_lookup_80164fc8 = 0x80164fc8;
w3d_post_80164514 = 0x80164514;
w3d_service_forward_8020b680 = 0x8020b680;
w3d_set_80133d64 = 0x80133d64;
w3d_set_pair_8002e558 = 0x8002e558;
w3d_type_8035fd90 = 0x8035fd90;
w3d_type_8035fe20 = 0x8035fe20;
w3d_type_8035ff70 = 0x8035ff70;
w3d_type_803600c0 = 0x803600c0;
w3d_type_80360210 = 0x80360210;
w3d_type_80360240 = 0x80360240;
w3d_type_80360390 = 0x80360390;
w3d_type_80360480 = 0x80360480;
w3d_type_80360540 = 0x80360540;
w3d_type_803605d0 = 0x803605d0;
w3d_type_80360660 = 0x80360660;
w3d_type_80360690 = 0x80360690;
w3d_type_80360840 = 0x80360840;
w3d_type_803608a0 = 0x803608a0;
w3d_type_80360ba0 = 0x80360ba0;
w3d_type_80360c30 = 0x80360c30;
w3d_type_80360c60 = 0x80360c60;
w3d_type_80360cc0 = 0x80360cc0;
w3d_type_80360d50 = 0x80360d50;
w3d_type_80361440 = 0x80361440;
w3d_type_80361470 = 0x80361470;
w3d_type_803615f0 = 0x803615f0;
w3d_type_80361620 = 0x80361620;
SECTIONS {
  .text.w3d_d26b_spawn_message_80096db4 0x80096db4 : { *(.text.w3d_d26b_spawn_message_80096db4) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_system_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
