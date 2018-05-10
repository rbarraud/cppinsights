/******************************************************************************
 *
 * C++ Insights, copyright (C) by Andreas Fertig
 * Distributed under an MIT license. See LICENSE for details
 *
 ****************************************************************************/

#ifndef INSIGHTS_AUTO_STMT_HANDLER_H
#define INSIGHTS_AUTO_STMT_HANDLER_H

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "InsightsBase.h"
//-----------------------------------------------------------------------------

namespace clang::insights {

/// \brief Show the types behind \c auto
///
/// For example:
/// \code
/// auto i = 0;
/// \endcode
///
/// will give you
/// \code
/// int i = 0;
/// \endcode
class AutoStmtHandler final : public ast_matchers::MatchFinder::MatchCallback, public InsightsBase
{
public:
    AutoStmtHandler(Rewriter& rewrite, ast_matchers::MatchFinder& matcher);
    void run(const ast_matchers::MatchFinder::MatchResult& result) override;
};
//-----------------------------------------------------------------------------

}  // namespace clang::insights

#endif /* INSIGHTS_AUTO_STMT_HANDLER_H */
