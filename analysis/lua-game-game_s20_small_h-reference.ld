/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_refresh_handle_8013f2f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800cd178 = 0x800cd178;
fn_80164fc8 = 0x80164fc8;
fn_8017e22c = 0x8017e22c;
fn_801857f4 = 0x801857f4;
fn_801a37a0 = 0x801a37a0;
fn_801d60cc = 0x801d60cc;
fn_803096b0 = 0x803096b0;
lbl_80412068 = 0x80412068;
SECTIONS {
  .text.w3d_s20_refresh_handle_8013f2f8 0x8013f2f8 : { *(.text.w3d_s20_refresh_handle_8013f2f8) }
  .text.w3d_s20_enable_slot_8016857c 0x8016857c : { *(.text.w3d_s20_enable_slot_8016857c) }
  .text.w3d_s20_construct_counted_80172b14 0x80172b14 : { *(.text.w3d_s20_construct_counted_80172b14) }
  .text.w3d_s20_lookup_slot_8017ded8 0x8017ded8 : { *(.text.w3d_s20_lookup_slot_8017ded8) }
  .text.w3d_s20_notify_then_apply_801d6550 0x801d6550 : { *(.text.w3d_s20_notify_then_apply_801d6550) }
  .sdata 0x804ab580 (NOLOAD) : {
    . = 0x0; lbl_804ab580 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
