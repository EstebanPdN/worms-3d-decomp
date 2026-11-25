/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d20e_dynamic_slot_80263cfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ae3c = 0x8015ae3c;
fn_80171ee0 = 0x80171ee0;
fn_80171fa0 = 0x80171fa0;
fn_80171ff8 = 0x80171ff8;
fn_80343808 = 0x80343808;
w3d_slot_value_803cb1fc = 0x803cb1fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d20e_dynamic_slot_80263cfc 0x80263cfc : { *(.text.w3d_d20e_dynamic_slot_80263cfc) }
  .rodata 0x803cb200 : { *(.rodata) }
  .sdata 0x804abb64 (NOLOAD) : {
    . = 0x0; w3d_slot_mask_804abb64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
