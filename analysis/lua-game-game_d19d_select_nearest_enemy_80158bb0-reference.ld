/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19d_select_nearest_enemy_80158bb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80023128 = 0x80023128;
fn_800a82f0 = 0x800a82f0;
fn_800fc6dc = 0x800fc6dc;
fn_800fc7f8 = 0x800fc7f8;
fn_80126034 = 0x80126034;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80178c48 = 0x80178c48;
fn_803426b4 = 0x803426b4;
SECTIONS {
  .text.d19d_select_nearest_enemy_80158bb0 0x80158bb0 : { *(.text.d19d_select_nearest_enemy_80158bb0) }
  .rodata 0x803a2cd4 : { *(.rodata) }
  .sdata 0x804aa7d4 (NOLOAD) : {
    . = 0x0; lbl_804aa7d4 = .;
    . = 0x571c; lbl_804afef0 = .;
    . = 0x5774; lbl_804aff48 = .;
    . = 0x5784; lbl_804aff58 = .;
    . = 0x578c; lbl_804aff60 = .;
    . = 0x6f80; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
