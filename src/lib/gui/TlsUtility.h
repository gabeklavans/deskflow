/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2024 Symless Ltd.
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "IAppConfig.h"

#include "license/License.h"
#include <stdexcept>

namespace synergy::gui {

class TlsUtility {
public:
  explicit TlsUtility(
      const IAppConfig &appConfig, const license::License &license)
      : m_appConfig(appConfig),
        m_license(license) {}

  /**
   * @brief Combines the availability and the enabled status of TLS.
   *
   * @return Given that the app setting for TLS is enabled:
   * If licensing is enabled, it checks whether the product has TLS
   * available, and if licensing is not enabled, true is returned.
   */
  bool isAvailableAndEnabled() const;

  /**
   * @return true if TLS is available, regardless of whether it is enabled.
   */
  bool isAvailable() const;

  /**
   * @param replace Replace certificate on disk (default: false).
   */
  void generateCertificate(bool replace = false) const;

private:
  const IAppConfig &m_appConfig;
  const license::License &m_license;
};

} // namespace synergy::gui