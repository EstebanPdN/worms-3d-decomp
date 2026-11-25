/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f6b_crate_explode_8004c850)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_80377360 = 0x80377360;
allocate_801613f0 = 0x801613f0;
b_8037737c = 0x8037737c;
c_80377394 = 0x80377394;
construct_800666b4 = 0x800666b4;
d_803773ac = 0x803773ac;
e_803773c4 = 0x803773c4;
effect_800e5ca4 = 0x800e5ca4;
effect_803773d8 = 0x803773d8;
finish_8015fd1c = 0x8015fd1c;
index_80377118 = 0x80377118;
intensity_803773fc = 0x803773fc;
name_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
read_800fc270 = 0x800fc270;
sound_803773f0 = 0x803773f0;
value_8040db38 = 0x8040db38;
write_800fc3b0 = 0x800fc3b0;
SECTIONS {
  .text.f6b_crate_explode_8004c850 0x8004c850 : { *(.text.f6b_crate_explode_8004c850) }
  .sdata 0x804ad350 (NOLOAD) : {
    . = 0x0; name_804ad350 = .;
    . = 0x4404; queue_804b1754 = .;
    . = 0x4438; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
