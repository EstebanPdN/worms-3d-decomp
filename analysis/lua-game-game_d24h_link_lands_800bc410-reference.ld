/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_link_lands_800bc410)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800bc390 = 0x800bc390;
fn_801ef048 = 0x801ef048;
fn_802eee50 = 0x802eee50;
lbl_8043bb64 = 0x8043bb64;
w3d_get_800b4d98 = 0x800b4d98;
SECTIONS {
  .text.w3d_d24h_link_lands_800bc410 0x800bc410 : { *(.text.w3d_d24h_link_lands_800bc410) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
