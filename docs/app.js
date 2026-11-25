"use strict";

/*
 * MAINTENANCE / ACTUALIZACIONES DE CIFRAS
 * Actualiza únicamente los datos verificados de progress.json mediante
 * build_data.py / export_site.py. No cambies HTML, CSS, colores, tipografía ni
 * las plantillas de este archivo al actualizar números. Consulta ../README.md.
 * Las explicaciones largas pertenecen a «How progress is measured», no al dial.
 */

// Shared formatting, status colors (owned by style.css) and application state.
const $ = (id) => document.getElementById(id);
const number = (n) => new Intl.NumberFormat("en-US").format(n);
const hex = (n) => "0x" + n.toString(16).padStart(8, "0");
const size = (n) =>
  n >= 1048576
    ? (n / 1048576).toLocaleString("en-US", { maximumFractionDigits: 2 }) +
      " MiB"
    : number(n) + " B";
const labels = {
  exact: "Exact source",
  behavior: "Behavior tested",
  pending: "Pending",
  unmapped: "Unassigned bytes",
};
const theme = getComputedStyle(document.documentElement);
const palette = Object.fromEntries(
  Object.keys(labels).map((state) => [
    state,
    theme.getPropertyValue(`--${state}`).trim(),
  ]),
);
const mapBackground = theme.getPropertyValue("--map-background").trim();
const filteredColor = theme.getPropertyValue("--map-filtered").trim();
const canvas = $("treemap");
const ctx = canvas.getContext("2d");
let data,
  groups = [],
  zoom = null,
  hitboxes = [],
  groupRects = [],
  selectedGroup = 0,
  filtered = [],
  page = 0,
  selection = null;
let busy = false,
  width = 0,
  height = 0;
const PAGE_SIZE = 20;

function field(list, label, value, code = false) {
  const row = document.createElement("div"),
    dt = document.createElement("dt"),
    dd = document.createElement("dd");
  dt.textContent = label;
  dd.textContent = value;
  if (code) dd.className = "code";
  row.append(dt, dd);
  list.append(row);
}

// Map grouping and layout: byte weights stay exact; only raster edges are rounded.
function groupParts() {
  const map = new Map();
  for (const [a, b, i] of data.parts) {
    const r = i >= 0 ? data.records[i] : null;
    // Split only the display fragments at bank boundaries. Never enlarge bytes.
    for (let start = a; start < b; ) {
      const end = Math.min(b, (Math.floor(start / 65536) + 1) * 65536);
      const bank = Math.floor(start / 65536) * 65536;
      const known =
        $("grouping").value === "module" && r && r.state !== "pending";
      const key = known ? "module:" + r.module : "bank:" + bank;
      if (!map.has(key))
        map.set(key, {
          key,
          name: known ? r.module : hex(bank).slice(0, -4) + "xxxx",
          subtitle: known ? "Known module" : "Unclassified region",
          bytes: 0,
          exact: 0,
          behavior: 0,
          parts: [],
          address: bank,
        });
      const g = map.get(key),
        state = r ? r.state : "unmapped";
      g.parts.push({ a: start, b: end, i, state, bytes: end - start });
      g.bytes += end - start;
      if (state === "exact") g.exact += end - start;
      if (state === "behavior") g.behavior += end - start;
      start = end;
    }
  }
  groups = [...map.values()].sort(
    (a, b) =>
      b.bytes - a.bytes || a.address - b.address || a.key.localeCompare(b.key),
  );
  if (zoom && !groups.some((g) => g.key === zoom)) zoom = null;
  selectedGroup = Math.min(selectedGroup, groups.length - 1);
}

// Display weights reserve visible space for tiny functions. Actual byte counts,
// ranges and progress remain untouched; the map caption identifies this scaling.
const MIN_TILE_SIDE = 3;

function readableGroups(active, area) {
  const count = active.reduce((sum, g) => sum + g.parts.length, 0);
  const bytes = active.reduce((sum, g) => sum + g.bytes, 0);
  const minimumArea = Math.min(MIN_TILE_SIDE ** 2, (area * 0.55) / count);
  // Enlarge only cells below the floor. Solve the remaining scale so larger
  // functions keep as much of their original proportions as available space allows.
  let lower = 0;
  let upper = area / bytes;
  for (let pass = 0; pass < 26; pass++) {
    const scale = (lower + upper) / 2;
    const used = active.reduce(
      (sum, g) =>
        sum +
        g.parts.reduce(
          (partSum, p) => partSum + Math.max(minimumArea, p.bytes * scale),
          0,
        ),
      0,
    );
    if (used > area) upper = scale;
    else lower = scale;
  }
  return active.map((g) => {
    const parts = g.parts.map((p) => ({
      ...p,
      displayWeight: Math.max(minimumArea, p.bytes * lower),
      smallCell: p.bytes * lower <= minimumArea * 1.5,
    }));
    return {
      ...g,
      parts,
      displayWeight: parts.reduce((sum, p) => sum + p.displayWeight, 0),
    };
  });
}

// Binary treemap with optional minimum dimensions. The same boundaries are
// shared by neighboring cells; cells never overlap or paint over one another.
function layout(
  items,
  x,
  y,
  w,
  h,
  callback,
  minimumSide = 0,
  smallStyle = null,
) {
  if (!items.length) return;
  if (items.length === 1) {
    callback(items[0], x, y, w, h);
    return;
  }
  if (
    smallStyle?.refine &&
    items.length >= 4 &&
    items.every((p) => p.smallCell)
  ) {
    const original = [];
    layout(
      items,
      x,
      y,
      w,
      h,
      (p, tx, ty, tw, th) => original.push({ p, tx, ty, tw, th }),
      minimumSide,
    );
    // Reflow only a complete small-cell subtree within its existing bounds.
    // Ordinary and large function rectangles therefore stay exactly in place.
    if (
      original.every(
        ({ tw, th }) =>
          tw <= smallStyle.maxSide &&
          th <= smallStyle.maxSide &&
          tw * th <= smallStyle.maxArea,
      )
    ) {
      const varied = items
        .map((p) => ({
          ...p,
          displayWeight:
            Math.pow(p.bytes, 0.7) *
            (0.8 +
              (tileHash(p.a ^ Math.imul(p.b, 0x9e3779b1)) / 0xffffffff) * 0.4),
        }))
        .sort((a, b) => tileHash(a.a) - tileHash(b.a) || a.a - b.a);
      return layout(
        varied,
        x,
        y,
        w,
        h,
        callback,
        Math.min(minimumSide, smallStyle.minimumSide),
        { ...smallStyle, refine: false },
      );
    }
  }
  const weights = items.map((i) => i.displayWeight ?? i.bytes);
  const units = [0];
  for (const item of items)
    units.push(units[units.length - 1] + (item.parts?.length ?? 1));
  const totalUnits = units[units.length - 1];
  const sum = weights.reduce((s, weight) => s + weight, 0);
  let part = 0,
    cut = 0;
  while (cut < items.length - 1 && part + weights[cut] <= sum / 2) {
    part += weights[cut];
    cut++;
  }
  if (!cut) {
    cut = 1;
    part = weights[0];
  }
  let ratio = part / sum;
  let vertical = w >= h;
  if (smallStyle && !smallStyle.refine && w / h > 0.65 && w / h < 1.55) {
    vertical =
      (tileHash(items[0].a ^ items[items.length - 1].b ^ items.length) & 1) ===
      0;
  }
  if (minimumSide) {
    let fitted = false;
    // Keep enough rows/columns in each branch to give every leaf a colored
    // interior plus its divider. Prefer the original byte-weighted split.
    for (const axis of [vertical, !vertical]) {
      const length = axis ? w : h;
      const cross = axis ? h : w;
      const slots = Math.max(1, Math.floor((cross + 1e-7) / minimumSide));
      const candidates = [
        ...new Set([
          cut,
          Math.floor(cut / slots) * slots,
          Math.ceil(cut / slots) * slots,
        ]),
      ].filter((n) => n > 0 && n < items.length);
      if (items[0].parts) {
        // Module groups need room for their functions, not just one group box.
        candidates.push(
          ...Array.from({ length: items.length - 1 }, (_, i) => i + 1).sort(
            (a, b) => Math.abs(a - cut) - Math.abs(b - cut),
          ),
        );
      }
      const candidate = candidates.find(
        (n) =>
          (Math.ceil(units[n] / slots) +
            Math.ceil((totalUnits - units[n]) / slots)) *
            minimumSide <=
          length + 1e-7,
      );
      if (candidate === undefined) continue;
      cut = candidate;
      part = weights.slice(0, cut).reduce((s, weight) => s + weight, 0);
      const lower = (Math.ceil(units[cut] / slots) * minimumSide) / length;
      const upper =
        1 -
        (Math.ceil((totalUnits - units[cut]) / slots) * minimumSide) / length;
      ratio = Math.max(lower, Math.min(upper, part / sum));
      vertical = axis;
      fitted = true;
      break;
    }
    if (!fitted && minimumSide > 1) {
      return layout(items, x, y, w, h, callback, minimumSide - 1, smallStyle);
    }
  }
  if (vertical) {
    const split = Math.round(w * ratio);
    layout(
      items.slice(0, cut),
      x,
      y,
      split,
      h,
      callback,
      minimumSide,
      smallStyle,
    );
    layout(
      items.slice(cut),
      x + split,
      y,
      w - split,
      h,
      callback,
      minimumSide,
      smallStyle,
    );
  } else {
    const split = Math.round(h * ratio);
    layout(
      items.slice(0, cut),
      x,
      y,
      w,
      split,
      callback,
      minimumSide,
      smallStyle,
    );
    layout(
      items.slice(cut),
      x,
      y + split,
      w,
      h - split,
      callback,
      minimumSide,
      smallStyle,
    );
  }
}

// Stable address-derived variation: refreshes never reshuffle the mosaic.
function tileHash(value) {
  value = Math.imul(value ^ (value >>> 16), 0x45d9f3b);
  value = Math.imul(value ^ (value >>> 16), 0x45d9f3b);
  return (value ^ (value >>> 16)) >>> 0;
}

function fittedTileSide(count, w, h, target = MIN_TILE_SIDE) {
  let side = Math.max(1, Math.floor(Math.min(target, w, h)));
  // Narrow screens can have more functions than physical cells. Use the largest
  // fitting size there; zooming grants those same functions more screen space.
  while (side > 1 && Math.floor(w / side) * Math.floor(h / side) < count)
    side--;
  return side;
}

function matches(r) {
  const filter = $("filter").value,
    q = $("search").value.toLowerCase().trim();
  return (
    (filter === "all" || r.state === filter) &&
    (!q ||
      [
        r.name,
        hex(r.address),
        r.module,
        r.source || "",
        r.description || "",
      ].some((s) => s.toLowerCase().includes(q)))
  );
}

/**
 * Paint on physical pixel boundaries, so tiny tiles do not blend with the blue
 * background. Adjacent tiles round the SAME boundary. The layout reserves a
 * minimum visual area before painting; byte values remain their original size.
 * Preserve a divider on EVERY tile, including small ones. The old 0.65 CSS-px
 * spacing is snapped to at least one physical pixel; never drop it based on
 * tile size, because doing so merges neighboring functions into solid patches.
 */
function paintTile(x, y, w, h, color, scaleX, scaleY) {
  const left = Math.round(x * scaleX);
  const top = Math.round(y * scaleY);
  const right = Math.round((x + w) * scaleX);
  const bottom = Math.round((y + h) * scaleY);
  const gapX = Math.max(1, Math.round(0.65 * scaleX));
  const gapY = Math.max(1, Math.round(0.65 * scaleY));
  ctx.save();
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.fillStyle = color;
  ctx.fillRect(
    left,
    top,
    Math.max(0, right - left - gapX),
    Math.max(0, bottom - top - gapY),
  );
  ctx.restore();
}

function draw() {
  if (!data || !ctx) return;
  const rect = canvas.getBoundingClientRect();
  // Narrow maps need a denser backing buffer to retain a colored pixel inside
  // each tiny divider, including on screens that report a pixel ratio of one.
  const dpr = Math.max(
    rect.width < 600 ? 2 : 1,
    Math.min(window.devicePixelRatio || 1, 2),
  );
  width = rect.width;
  height = rect.height;
  if (!width || !height) return;
  canvas.width = Math.round(width * dpr);
  canvas.height = Math.round(height * dpr);
  // Match the backing buffer even at fractional browser zoom / pixel ratios.
  const scaleX = canvas.width / width;
  const scaleY = canvas.height / height;
  ctx.setTransform(scaleX, 0, 0, scaleY, 0, 0);
  ctx.fillStyle = mapBackground;
  ctx.fillRect(0, 0, width, height);
  hitboxes = [];
  groupRects = [];
  const active = readableGroups(
    zoom ? groups.filter((g) => g.key === zoom) : groups,
    width * height,
  );
  layout(
    active,
    0,
    0,
    canvas.width,
    canvas.height,
    (g, gx, gy, gw, gh) => {
      const x = gx / scaleX,
        y = gy / scaleY,
        w = gw / scaleX,
        h = gh / scaleY;
      // Tiny module groups already have a cell divider; an extra group gutter
      // would consume the only colored pixels in those groups.
      const gutter = g.key.startsWith("module:")
        ? 0
        : Math.round(Math.min(scaleX, scaleY));
      const innerWidth = Math.max(0, gw - gutter * 2);
      const innerHeight = Math.max(0, gh - gutter * 2);
      groupRects.push({ g, x, y, w, h });
      layout(
        g.parts,
        gx + gutter,
        gy + gutter,
        innerWidth,
        innerHeight,
        (p, tx, ty, tw, th) => {
          const px = tx / scaleX,
            py = ty / scaleY,
            pw = tw / scaleX,
            ph = th / scaleY;
          const r = p.i >= 0 ? data.records[p.i] : null;
          // Filters use a neutral color, never a second, darker "exact" green.
          const visible = r
            ? matches(r)
            : $("filter").value === "all" && !$("search").value.trim();
          paintTile(
            px,
            py,
            pw,
            ph,
            visible ? palette[p.state] : filteredColor,
            scaleX,
            scaleY,
          );
          if ($("show-map-labels").checked && zoom && pw > 90 && ph > 22 && r) {
            ctx.save();
            ctx.beginPath();
            ctx.rect(px + 3, py + 1, pw - 6, ph - 2);
            ctx.clip();
            ctx.fillStyle =
              p.state === "exact" || p.state === "behavior"
                ? "#101a0e"
                : "#dce4d7";
            ctx.font = "10px Arial";
            ctx.fillText(r.name, px + 4, py + 14);
            ctx.restore();
          }
          if (pw > 0.5 && ph > 0.5)
            hitboxes.push({ p, x: px, y: py, w: pw, h: ph, g });
        },
        fittedTileSide(
          g.parts.length,
          innerWidth,
          innerHeight,
          MIN_TILE_SIDE * Math.min(scaleX, scaleY),
        ),
        {
          refine: true,
          maxSide: 8 * Math.min(scaleX, scaleY),
          maxArea: 24 * scaleX * scaleY,
          minimumSide: Math.max(2, Math.floor(2 * Math.min(scaleX, scaleY))),
        },
      );
      if ($("show-map-labels").checked && !zoom && w > 74 && h > 28) {
        ctx.save();
        ctx.beginPath();
        ctx.rect(x + 2, y + 2, w - 4, h - 4);
        ctx.clip();
        ctx.font = "11px Arial";
        const tw = Math.min(w - 4, ctx.measureText(g.name).width + 12);
        ctx.fillStyle = "#061d3bf0";
        ctx.fillRect(x + 2, y + 2, tw, 19);
        ctx.fillStyle = "#ffffff";
        ctx.fillText(g.name, x + 7, y + 15);
        ctx.restore();
      }
      if (
        !zoom &&
        document.activeElement === canvas &&
        groups[selectedGroup]?.key === g.key
      ) {
        ctx.strokeStyle = "#eff3e7";
        ctx.lineWidth = 2;
        ctx.strokeRect(x + 2, y + 2, w - 4, h - 4);
      }
    },
    $("grouping").value === "module"
      ? fittedTileSide(
          active.reduce((sum, g) => sum + g.parts.length, 0),
          canvas.width,
          canvas.height,
          MIN_TILE_SIDE * Math.min(scaleX, scaleY),
        )
      : 0,
  );
  $("back").hidden = !zoom;
  $("map-filter-note").hidden =
    $("filter").value === "all" && !$("search").value.trim();
}

// Selection inspector: overview, region and individual function.
function showOverview() {
  selection = null;
  const completed = data.summary.exact_functions;
  const remaining = Math.max(0, data.inventory.length - completed);
  $("detail-name").textContent =
    "Functions - " +
    number(completed) +
    " exact · " +
    number(remaining) +
    " remaining";
  $("detail-name").setAttribute(
    "aria-label",
    number(completed) +
      " decompiled functions / " +
      number(remaining) +
      " remaining functions",
  );
  $("detail-description").textContent = "";
  $("detail-values").replaceChildren();
  $("inspect-region").hidden = true;
}
function returnToOverview() {
  zoom = null;
  $("map-tip").hidden = true;
  showOverview();
  draw();
}

function showGroup(g) {
  selection = { kind: "group", key: g.key };
  $("detail-name").removeAttribute("aria-label");
  $("detail-name").textContent = g.name;
  $("detail-description").textContent = g.key.startsWith("bank:")
    ? "Address region. Subsystem not yet identified."
    : "Functions grouped by recovered source file.";
  const list = $("detail-values");
  list.replaceChildren();
  field(list, "Mapped code", size(g.bytes));
  field(list, "Exact source", size(g.exact));
  field(list, "Behavior tested", size(g.behavior));
  field(list, "Pending", size(g.bytes - g.exact - g.behavior));
  $("inspect-region").hidden = Boolean(zoom);
  $("inspect-region").onclick = () => {
    zoom = g.key;
    showGroup(g);
    draw();
  };
}

function showRecord(i, fragment = null) {
  const r = data.records[i];
  selection = { kind: "record", address: r.address };
  $("detail-name").removeAttribute("aria-label");
  $("detail-name").textContent = r.name;
  $("detail-description").textContent =
    r.description ||
    (r.state === "exact"
      ? "Recompiled source matches the original instructions."
      : r.state === "behavior"
        ? "Compiled source passes bounded comparisons with the original."
        : "Inferred function. Source recovery and verification pending.");
  const list = $("detail-values");
  list.replaceChildren();
  field(list, "Address", hex(r.address), true);
  field(list, "Body size", size(r.bytes));
  field(list, "Status", labels[r.state]);
  if (fragment)
    field(
      list,
      "Selected bytes",
      hex(fragment.a) + " to " + hex(fragment.b - 1),
      true,
    );
  field(
    list,
    "Inclusive ranges",
    r.ranges.map(([a, b]) => hex(a) + " to " + hex(b - 1)).join("\n"),
    true,
  );
  if (r.source) field(list, "Source", r.source, true);
  if (r.receipt) field(list, "Evidence", r.receipt, true);
  $("inspect-region").hidden = true;
}

// Searchable, paginated function inventory.
function renderRows() {
  if (!data) return;
  filtered = data.inventory.filter((i) => matches(data.records[i]));
  const pages = Math.max(1, Math.ceil(filtered.length / PAGE_SIZE));
  page = Math.max(0, Math.min(page, pages - 1));
  const body = $("function-rows");
  body.replaceChildren();
  for (const i of filtered.slice(page * PAGE_SIZE, (page + 1) * PAGE_SIZE)) {
    const r = data.records[i],
      tr = document.createElement("tr"),
      nameCell = document.createElement("td"),
      button = document.createElement("button"),
      addr = document.createElement("small");
    button.type = "button";
    button.textContent = r.name;
    button.setAttribute(
      "aria-label",
      "Details for " + r.name + ", " + hex(r.address),
    );
    button.onclick = () => {
      showRecord(i);
      $("inspector").scrollIntoView({
        behavior: window.matchMedia("(prefers-reduced-motion: reduce)").matches
          ? "instant"
          : "smooth",
        block: "center",
      });
    };
    addr.textContent = hex(r.address);
    nameCell.append(button, addr);
    if (r.description) {
      const description = document.createElement("p");
      description.className = "function-description";
      description.textContent = r.description;
      nameCell.append(description);
    }
    tr.append(nameCell);
    const module = document.createElement("td");
    module.textContent = r.module;
    tr.append(module);
    const bytes = document.createElement("td");
    bytes.textContent = size(r.bytes);
    tr.append(bytes);
    const status = document.createElement("td"),
      label = document.createElement("span"),
      swatch = document.createElement("i");
    label.className = "status-text";
    swatch.className = "swatch " + r.state;
    swatch.setAttribute("aria-hidden", "true");
    label.append(swatch, document.createTextNode(labels[r.state]));
    status.append(label);
    tr.append(status);
    body.append(tr);
  }
  $("result-count").textContent =
    number(filtered.length) +
    (filtered.length === 1 ? " function" : " functions");
  $("empty").hidden = filtered.length > 0;
  $("page-info").textContent = filtered.length
    ? "Page " + number(page + 1) + " of " + number(pages)
    : "0 results";
  $("previous").disabled = page === 0;
  $("next").disabled = page + 1 >= pages;
}

// Stable presentation templates: data refreshes change values, not the layout.
function renderSummary() {
  const s = data.summary;
  // Truncate, never round up: the dial must not show more than is verified.
  $("percentage-value").textContent = (Math.floor(s.percent * 10) / 10).toLocaleString("en-US", {
    minimumFractionDigits: 1,
    maximumFractionDigits: 1,
  });
  const progress = Math.max(0, Math.min(100, s.percent));
  $("progress-fill").setAttribute(
    "stroke-dasharray",
    progress + " " + (100 - progress),
  );
  document
    .querySelector("[role=progressbar]")
    .setAttribute("aria-valuenow", s.percent.toFixed(4));
  $("byte-progress").textContent =
    number(s.exact_bytes) + " / " + number(s.total_bytes) + " bytes";
  const estimate = s.time_estimate;
  const rate = estimate && estimate.recent_rate;
  const hoursText = (h) =>
    h.toLocaleString("en-US", {
      minimumFractionDigits: 1,
      maximumFractionDigits: 1,
    });
  const recentHours = rate && rate.remaining_hours;
  const remainingHours = Number.isFinite(recentHours)
    ? recentHours
    : estimate && estimate.hours;
  $("completion-estimate").textContent = Number.isFinite(remainingHours)
    ? "≈ " + hoursText(remainingHours) + " hours left"
    : "Estimate pending";
  $("completion-estimate").title =
    (Number.isFinite(recentHours)
      ? rate.method
      : estimate && estimate.explanation) || "";
  $("hours-worked").textContent =
    estimate && Number.isFinite(estimate.worked_hours)
      ? "≈ " + hoursText(estimate.worked_hours) + " hours worked"
      : "";
  $("hours-worked").title = estimate
    ? estimate.worked_hours_source +
      " as of " +
      new Date(estimate.basis_updated_at).toLocaleString("en-US")
    : "";
  $("exact-count").textContent = number(s.exact_functions);
  document.querySelector(".time-divider").hidden =
    !$("hours-worked").textContent;
  $("inferred-count").textContent = number(s.inferred_functions);
  $("total-size").textContent = size(s.total_bytes);
  $("snapshot").textContent =
    "Snapshot: " + new Date(data.updated_at).toLocaleString("en-US");
  const facts = $("scope-facts");
  facts.replaceChildren();
  // Keep the estimate's assumptions readable outside the compact circle.
  if (Number.isFinite(recentHours)) {
    field(
      facts,
      "Recent pace estimate",
      `≈ ${hoursText(recentHours)} h left at the last ${number(rate.window_worked_hours)} worked hours' pace (${number(rate.percent_per_hour)}% per hour).`,
    );
  }
  if (estimate && Number.isFinite(estimate.hours)) {
    field(facts, "Overall estimate", `≈ ${hoursText(estimate.hours)} h left`);
  }
  if (rate?.method || estimate?.explanation) {
    field(facts, "Estimate basis", rate?.method || estimate.explanation);
  }
  field(
    facts,
    "Initialized data",
    size(data.data_sections.reduce((s, r) => s + r.bytes, 0)),
  );
  field(facts, "BSS", size(data.bss.bytes));
  field(facts, "Verified owned data", size(s.owned_data_bytes));
  field(
    facts,
    "Preserved Lua scripts",
    number(data.scripts_count ?? data.scripts?.length ?? 0),
  );
  field(facts, "Extracted files", number(data.resources.files));
  field(facts, "Unassigned code", size(s.status_bytes.unmapped || 0));
  if (s.binary_reference)
    field(
      facts,
      "Binary reference",
      "Complete file identical; binary-derived, no source credit",
    );
  if (s.request_transfer)
    field(
      facts,
      "Transfer experiment",
      "32 fixtures; 760 / 784 selected bytes executed; timeout untested",
    );
  if (s.mixed_reference)
    field(
      facts,
      "Frozen mixed reference",
      number(s.mixed_reference.source_functions_linked) +
        " functions / " +
        number(s.mixed_reference.source_instruction_bytes_linked) +
        " instruction bytes from recovered source; remainder binary-derived",
    );
  if (s.mixed_reference?.source_initialized_data_bytes)
    field(
      facts,
      "Mixed source data",
      number(s.mixed_reference.source_initialized_data_bytes) +
        " initialized bytes replaced in both exact full images (9 data objects / 23 section extents); " +
        number(s.mixed_reference.binary_initialized_data_bytes) +
        " initialized bytes remain binary-derived; source BSS 0; fixed address, same host; no full-source game, runtime or 3DS proof",
    );
  if (s.source_data_replay)
    field(
      facts,
      "Data replay catalog",
      number(s.source_data_replay.source_initialized_bytes) +
        " bytes / " +
        number(s.source_data_replay.independently_replayed_relocations) +
        " pointer relocations verified separately; this older catalog did not replace full-image data",
    );
  if (s.native_construction)
    field(
      facts,
      "Construction experiment",
      number(s.native_construction.fixtures) +
        " fixtures; " +
        number(s.native_construction.repeated_runs) +
        " fresh runs including owner; all 1,972 selected bytes executed; common wrappers 364 / 420 bytes, 56 unexecuted; external cores and virtual dependencies modeled; no added coverage credit",
    );
  if (s.request_storage)
    field(
      facts,
      "Storage experiment",
      "53 fixtures; all 544 selected bytes executed; external services modeled",
    );
}

// Synchronization: retain the last verified snapshot when an update fails.
async function refresh(manual = false) {
  if (busy) return;
  busy = true;
  $("refresh").disabled = true;
  try {
    const response = await fetch("progress.json", {
      cache: "no-store",
      signal: AbortSignal.timeout(15000),
    });
    if (!response.ok)
      throw new Error(
        "Could not load the inventory (" + response.status + ").",
      );
    const next = await response.json();
    if (
      next.schema !== 1 ||
      !next.summary ||
      !next.records?.length ||
      next.parts.reduce((s, p) => s + p[1] - p[0], 0) !==
        next.summary.total_bytes
    )
      throw new Error("Inventory integrity check failed.");
    if (!data || data.fingerprint !== next.fingerprint) {
      data = next;
      groupParts();
      renderSummary();
      renderRows();
      draw();
      if (selection?.kind === "record") {
        const i = data.inventory.find(
          (i) => data.records[i].address === selection.address,
        );
        if (i !== undefined) showRecord(i);
      } else if (!selection) showOverview();
    }
    $("error").hidden = true;
    $("sync-text").textContent =
      "Updated " +
      new Date(data.updated_at).toLocaleString("en-US", {
        month: "long",
        day: "numeric",
        hour: "numeric",
        minute: "2-digit",
        timeZone: "America/Los_Angeles",
      });
    if (manual) $("sync-text").textContent += " · checked";
  } catch (error) {
    const message =
      error instanceof TypeError || error.name === "TimeoutError"
        ? "Could not sync progress."
        : error.message;
    $("error").textContent =
      message +
      (data ? " Showing the last valid snapshot." : " Please try Refresh.");
    $("error").hidden = false;
    $("sync-text").textContent = "Offline";
  } finally {
    busy = false;
    $("refresh").disabled = false;
  }
}

// Pointer, keyboard and form interactions.
function point(event) {
  const r = canvas.getBoundingClientRect();
  return { x: event.clientX - r.left, y: event.clientY - r.top };
}
function hit(event, boxes) {
  const p = point(event);
  return boxes.find(
    (b) => p.x >= b.x && p.x < b.x + b.w && p.y >= b.y && p.y < b.y + b.h,
  );
}
canvas.addEventListener("pointermove", (event) => {
  const h = zoom ? hit(event, hitboxes) : hit(event, groupRects);
  if (!h) {
    $("map-tip").hidden = true;
    return;
  }
  const r = zoom && h.p.i >= 0 ? data.records[h.p.i] : null;
  $("map-tip").textContent = r
    ? r.name +
      " · " +
      hex(r.address) +
      " · " +
      size(h.p.bytes) +
      " · " +
      labels[r.state]
    : zoom
      ? "Unassigned bytes · " + hex(h.p.a)
      : h.g.name +
        " · " +
        size(h.g.bytes) +
        " · " +
        ((100 * h.g.exact) / h.g.bytes).toFixed(2) +
        "% exact";
  $("map-tip").hidden = false;
});
canvas.addEventListener("pointerleave", () => {
  $("map-tip").hidden = true;
});
canvas.addEventListener("click", (event) => {
  if (!data) return;
  if (!zoom) {
    const h = hit(event, groupRects);
    if (h) {
      zoom = h.g.key;
      showGroup(h.g);
      draw();
    }
  } else {
    const h = hit(event, hitboxes);
    if (h && h.p.i >= 0) showRecord(h.p.i, h.p);
    else if (h) {
      $("detail-name").removeAttribute("aria-label");
      $("detail-name").textContent = "Unassigned bytes";
      $("detail-description").textContent =
        "Outside inferred function boundaries. Classification pending.";
      $("detail-values").replaceChildren();
      field(
        $("detail-values"),
        "Range",
        hex(h.p.a) + " to " + hex(h.p.b - 1),
        true,
      );
      field($("detail-values"), "Size", size(h.p.bytes));
    }
  }
});
canvas.addEventListener("keydown", (event) => {
  if (!data) return;
  if (event.key === "Escape") {
    returnToOverview();
    event.preventDefault();
  } else if (
    event.key === "ArrowRight" ||
    event.key === "ArrowDown" ||
    event.key === "ArrowLeft" ||
    event.key === "ArrowUp"
  ) {
    if (zoom) {
      zoom = null;
    }
    selectedGroup =
      (selectedGroup +
        (event.key === "ArrowLeft" || event.key === "ArrowUp" ? -1 : 1) +
        groups.length) %
      groups.length;
    showGroup(groups[selectedGroup]);
    draw();
    event.preventDefault();
  } else if (event.key === "Enter" && !zoom) {
    zoom = groups[selectedGroup].key;
    showGroup(groups[selectedGroup]);
    draw();
    event.preventDefault();
  }
});
canvas.addEventListener("focus", draw);
canvas.addEventListener("blur", draw);
$("back").onclick = returnToOverview;
$("grouping").onchange = () => {
  if (!data) return;
  zoom = null;
  groupParts();
  showOverview();
  draw();
};
$("refresh").onclick = () => refresh(true);
$("show-map-labels").onchange = () => draw();
$("search").oninput = () => {
  page = 0;
  renderRows();
  draw();
};
$("filter").onchange = () => {
  page = 0;
  renderRows();
  draw();
};
$("previous").onclick = () => {
  page--;
  renderRows();
};
$("next").onclick = () => {
  page++;
  renderRows();
};
// Downloads always use the current validated snapshot and table filters.
function downloadText(filename, type, content) {
  const url = URL.createObjectURL(new Blob([content], { type })),
    a = document.createElement("a");
  a.href = url;
  a.download = filename;
  a.click();
  setTimeout(() => URL.revokeObjectURL(url), 1000);
}
$("export-json").onclick = () => {
  if (data)
    downloadText(
      "worms3d-progress.json",
      "application/json",
      JSON.stringify(data),
    );
};
$("export").onclick = () => {
  if (!data) return;
  const escape = (value) =>
    '"' + String(value ?? "").replaceAll('"', '""') + '"';
  const rows = [
    [
      "address",
      "name",
      "description",
      "state",
      "body_bytes",
      "module",
      "inclusive_ranges",
      "source",
      "evidence",
    ],
  ];
  for (const i of filtered) {
    const r = data.records[i];
    rows.push([
      hex(r.address),
      r.name,
      r.description,
      labels[r.state],
      r.bytes,
      r.module,
      r.ranges.map(([a, b]) => hex(a) + ".." + hex(b - 1)).join(";"),
      r.source,
      r.receipt,
    ]);
  }
  downloadText(
    "worms3d-functions-" + $("filter").value + ".csv",
    "text/csv;charset=utf-8;",
    "\uFEFF" + rows.map((row) => row.map(escape).join(",")).join("\r\n"),
  );
};
new ResizeObserver(draw).observe(canvas);
setInterval(() => {
  if (!document.hidden) refresh();
}, 30000);
refresh();
