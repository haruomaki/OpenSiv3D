﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2022 Ryo Suzuki
//	Copyright (c) 2016-2022 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/DirectoryWatcher.hpp>
# include <Siv3D/DirectoryWatcher/DirectoryWatcherDetail.hpp>

namespace s3d
{
	DirectoryWatcher::DirectoryWatcher()
	{
		// do nothing
	}

	DirectoryWatcher::DirectoryWatcher(const FilePath& directory)
		: pImpl{ std::make_shared<DirectoryWatcherDetail>(directory) }
	{
		// do nothing
	}

	DirectoryWatcher::~DirectoryWatcher()
	{
		// do nothing
	}

	bool DirectoryWatcher::isOpen() const
	{
		if (not pImpl)
		{
			return false;
		}

		return pImpl->isActive();
	}

	DirectoryWatcher::operator bool() const
	{
		return isOpen();
	}

	Array<FileChange> DirectoryWatcher::retrieveChanges() const
	{
		if (not pImpl)
		{
			return{};
		}

		Array<FileChange> changes;

		if (not retrieveChanges(changes))
		{
			return{};
		}

		return changes;
	}

	bool DirectoryWatcher::retrieveChanges(Array<FileChange>& fileChanges) const
	{
		if (not pImpl)
		{
			fileChanges.clear();
			return false;
		}

		pImpl->retrieveChanges(fileChanges);

		return (not fileChanges.isEmpty());
	}

	void DirectoryWatcher::clearChanges()
	{
		if (not pImpl)
		{
			return;
		}

		pImpl->clearChanges();
	}

	FilePath DirectoryWatcher::directory() const
	{
		if (not pImpl)
		{
			return{};
		}

		return pImpl->directory();
	}
}
