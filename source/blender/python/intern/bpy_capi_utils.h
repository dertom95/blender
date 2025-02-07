/* SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup pythonintern
 */

#pragma once

#if PY_VERSION_HEX < 0x03090000
#  error "Python 3.9 or greater is required, you'll need to update your Python."
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct EnumPropertyItem;
struct ReportList;

/* error reporting */
short BPy_reports_to_error(struct ReportList *reports, PyObject *exception, bool clear);
/**
 * A version of #BKE_report_write_file_fp that uses Python's stdout.
 */
void BPy_reports_write_stdout(const struct ReportList *reports, const char *header);
bool BPy_errors_to_report_ex(struct ReportList *reports,
                             const char *error_prefix,
                             bool use_full,
                             bool use_location);
bool BPy_errors_to_report_brief_with_prefix(struct ReportList *reports, const char *error_prefix);
bool BPy_errors_to_report(struct ReportList *reports);

struct bContext *BPY_context_get(void);

extern void bpy_context_set(struct bContext *C, PyGILState_STATE *gilstate);
/**
 * Context should be used but not now because it causes some bugs.
 */
extern void bpy_context_clear(struct bContext *C, const PyGILState_STATE *gilstate);

#ifdef __cplusplus
}
#endif
