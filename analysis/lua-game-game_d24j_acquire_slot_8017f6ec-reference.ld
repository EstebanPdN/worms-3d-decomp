/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24j_acquire_slot_8017f6ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10a_add_count_80190438 = 0x80190438;
d10a_kind_counts_804a89d8 = 0x804a89d8;
fn_8017ffbc = 0x8017ffbc;
SECTIONS {
  .text.d24j_acquire_slot_8017f6ec 0x8017f6ec : { *(.text.d24j_acquire_slot_8017f6ec) }
  .sdata 0x804ab60c (NOLOAD) : {
    . = 0x0; lbl_804ab60c = .;
    . = 0xc; lbl_804ab618 = .;
    . = 0x10; lbl_804ab61c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
