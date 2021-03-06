/**
 * Session class
 *
 * Copyright 2013 Thinstuff Technologies GmbH
 * Copyright 2013 DI (FH) Martin Haimberger <martin.haimberger@thinstuff.at>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <config.h>
#include <string>
#include <list>

#include <winpr/handle.h>
#include <module/modules.h>

namespace freerds{
	namespace sessionmanager{
		namespace session{

		class Session{
		public:
			Session(long sessionID);
			~Session();

			std::string getDomain();
			void setDomain(std::string groupname);
			std::string getUserName();
			void setUserName(std::string username);
			long getSessionID();

			bool generateUserToken();
			bool generateEnvBlockAndModify();
			char ** getPEnvBlock();

			void setModuleName(std::string moduleName);
			bool startModule(std::string & pipeName);
			bool stopModule();



		private:
			long mSessionID;
			bool mSessionStarted;

			std::string mUsername;
			std::string mDomain;

			HANDLE mUserToken;
			char * mpEnvBlock;

			std::string mModuleName;
			RDS_MODULE_COMMON * mCurrentModuleContext;

		};

		}
	}
}

namespace sessionNS = freerds::sessionmanager::session;

#endif
