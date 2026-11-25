/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(load__8D32sAnimP11D32sAnimObj)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_M_fill_insert__Q24_STLt6vector2Z15D32sAnimBindingZt15ModuleAllocator1Z15D32sAnimBindingP15D32sAnimBindingUiRC15D32sAnimBinding = 0x803501ac;
_M_fill_insert__Q24_STLt6vector2ZfZt15ModuleAllocator1ZfPfUiRCf = 0x80350848;
lbl_803a834c = 0x803a834c;
lbl_804164c0 = 0x804164c0;
w3d_cx11b_string_truncate_8020c3a0 = 0x8020c3a0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s21_apply_unless_two_801eb240 = 0x801eb240;
w3d_s21_vector_get_801e9db8 = 0x801e9db8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.load__8D32sAnimP11D32sAnimObj 0x801953e8 : { *(.text.load__8D32sAnimP11D32sAnimObj) }
  .rodata 0x803a83dc : { *(.rodata) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; lbl_804b0640 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
