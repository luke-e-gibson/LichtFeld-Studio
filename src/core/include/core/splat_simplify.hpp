/* SPDX-FileCopyrightText: 2026 LichtFeld Studio Authors
 *
 * SPDX-License-Identifier: GPL-3.0-or-later */

#pragma once

#include "core/export.hpp"
#include "core/splat_simplify_history.hpp"
#include "core/splat_simplify_types.hpp"

#include <expected>
#include <memory>

namespace lfs::core {

    class SplatData;

    struct SplatSimplifyResult {
        std::unique_ptr<SplatData> splat;
        SplatSimplifyMergeTree merge_tree;
    };

    LFS_CORE_API std::expected<std::unique_ptr<SplatData>, std::string> simplify_splats(
        const SplatData& input,
        const SplatSimplifyOptions& options = {},
        SplatSimplifyProgressCallback progress = {});

    LFS_CORE_API std::expected<SplatSimplifyResult, std::string> simplify_splats_with_history(
        const SplatData& input,
        const SplatSimplifyOptions& options = {},
        SplatSimplifyProgressCallback progress = {});

} // namespace lfs::core
