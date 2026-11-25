/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27g_refill_sorted_list_80050534)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
qsort_802ede44 = 0x802ede44;
w3d_cmp_800504d0 = 0x800504d0;
w3d_count_800fc668 = 0x800fc668;
w3d_list_clear_80210afc = 0x80210afc;
w3d_list_resize_80210b90 = 0x80210b90;
w3d_next_800fc69c = 0x800fc69c;
SECTIONS {
  .text.w3d_d27g_refill_sorted_list_80050534 0x80050534 : { *(.text.w3d_d27g_refill_sorted_list_80050534) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
