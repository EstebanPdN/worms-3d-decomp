/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_geyser_sky_step_8004f238)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
col_804299e8 = 0x804299e8;
dir_804299dc = 0x804299dc;
effect_803778fc = 0x803778fc;
fn_80162C40 = 0x80162c40;
step_804299d0 = 0x804299d0;
w3d_engine_get_context = 0x80165254;
w3d_s20_forward_global_800e5ca4 = 0x800e5ca4;
SECTIONS {
  .text.w3d_d29g_geyser_sky_step_8004f238 0x8004f238 : { *(.text.w3d_d29g_geyser_sky_step_8004f238) }
  .rodata 0x80377908 : { *(.rodata) }
  .sdata 0x804aa9ec (NOLOAD) : {
    . = 0x0; last_804aa9ec = .;
    . = 0x4; wait_804aa9f0 = .;
    . = 0x2a80; guard_804ad46c = .;
    . = 0x2a84; guard_804ad470 = .;
    . = 0x2a88; guard_804ad474 = .;
    . = 0x6d9c; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
