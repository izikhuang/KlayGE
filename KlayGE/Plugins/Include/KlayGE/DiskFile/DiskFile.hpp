// DiskFile.hpp
// KlayGE 磁盘文件类 头文件
// Ver 2.0.0
// 版权所有(C) 龚敏敏, 2003
// Homepage: http://www.enginedev.com
//
// 2.0.0
// 初次建立 (2003.8.10)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#ifndef _DISKFILE_HPP
#define _DISKFILE_HPP

#include <KlayGE/VFile.hpp>
#include <KlayGE/SharedPtr.hpp>
#include <fstream>

#pragma comment(lib, "KlayGE_FileSystem_DiskFile.lib")

namespace KlayGE
{
	// 管理磁盘文件读写
	/////////////////////////////////////////////////////////////////////////////////
	class DiskFile : public VFile
	{
	public:
		DiskFile();
		DiskFile(const WString& fileName, OpenMode openMode);
		~DiskFile();

		bool Open(const WString& fileName, OpenMode openMode);
		void Close();

		size_t Length();
		void Length(size_t newLen);

		size_t Write(const void* data, size_t count);
		size_t Read(void* data, size_t count);
		size_t CopyFrom(VFile& src, size_t size);

		size_t Seek(size_t offset, SeekMode from);
		size_t Tell();

		void Flush();

	private:
		std::fstream file_;

		WString		fileName_;
		OpenMode	openMode_;

		DiskFile(const DiskFile& rhs);
		DiskFile& operator=(const DiskFile& rhs);
	};
}

#endif			// _DISKFILE_HPP