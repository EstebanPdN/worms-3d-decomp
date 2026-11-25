/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_destroy_owned_resources_800a60e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A5DB0 = 0x800a5db0;
fn_8015F884 = 0x8015f884;
fn_801628EC = 0x801628ec;
fn_801FE1F8 = 0x801fe1f8;
fn_80209920 = 0x80209920;
fn_802134FC = 0x802134fc;
lbl_8040F628 = 0x8040f628;
SECTIONS {
  .text.s8_destroy_owned_resources_800a60e8 0x800a60e8 : { *(.text.s8_destroy_owned_resources_800a60e8) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; lbl_804AAC54 = .;
    . = 0x362c; lbl_804AE280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
