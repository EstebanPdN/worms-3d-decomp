"use strict";
// Center the whole gauge within the visible logo/description span.
// The supplied logo's visible artwork starts at row 42 of its 256px image.
(() => {
  const copy = document.querySelector(".intro-copy");
  const intro = document.querySelector(".intro");
  const header = document.querySelector(".masthead");
  const logo = document.querySelector(".hero-logo");
  const description = document.querySelector(".hero-description");
  const summary = document.querySelector(".progress-summary");
  const dial = document.querySelector(".progress-dial");
  const details = document.querySelector(".progress-details");
  const stacked = window.matchMedia("(max-width:880px)");
  let offset = 0;
  let lift = 0;

  function alignGauge() {
    // Keep a consistent breathing space below navigation, ignoring PNG padding.
    const originalLogo = logo.getBoundingClientRect();
    lift =
      Math.round(
        Math.max(
          0,
          originalLogo.top +
            (originalLogo.height * 42) / 256 +
            lift -
            header.getBoundingClientRect().bottom -
            32,
        ) * 100,
      ) / 100;
    intro.style.setProperty("--hero-lift", -lift + "px");
    if (stacked.matches) {
      offset = 0;
      summary.style.removeProperty("--gauge-offset");
      dial.style.removeProperty("--gauge-size");
      return;
    }
    const logoBox = logo.getBoundingClientRect();
    const top = logoBox.top + (logoBox.height * 42) / 256;
    const bottom = description.getBoundingClientRect().bottom;
    // Include the complete details card after font loads and data refreshes.
    const captionsHeight =
      details.getBoundingClientRect().bottom -
      dial.getBoundingClientRect().bottom;
    const cap = parseFloat(
      getComputedStyle(dial).getPropertyValue("--gauge-max"),
    );
    const diameter = Math.max(
      168,
      Math.min(cap, summary.clientWidth, bottom - top - captionsHeight) * 0.85,
    );
    dial.style.setProperty("--gauge-size", diameter.toFixed(2) + "px");
    const naturalTop = dial.getBoundingClientRect().top - offset;
    const naturalBottom = details.getBoundingClientRect().bottom - offset;
    const centeredOffset = (top + bottom - naturalTop - naturalBottom) / 2;
    offset = Math.round(centeredOffset * 100) / 100;
    summary.style.setProperty("--gauge-offset", offset.toFixed(2) + "px");
  }

  const observer = new ResizeObserver(alignGauge);
  observer.observe(copy);
  observer.observe(header);
  observer.observe(summary);
  observer.observe(details);
  logo.addEventListener("load", alignGauge);
  stacked.addEventListener("change", alignGauge);
  document.fonts.ready.then(alignGauge);
  alignGauge();
})();
