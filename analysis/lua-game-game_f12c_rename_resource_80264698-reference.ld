/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f12c_rename_resource_80264698)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._24F12cRenameOwned_80178474 = 0x80178474;
__23F12cRenameText_8020bb54PCc = 0x8020bb54;
fn_80179598 = 0x80179598;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_f12c_rename_resource_80264698 0x80264698 : { *(.text.w3d_f12c_rename_resource_80264698) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
