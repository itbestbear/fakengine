/* This file is generated by genstat. */
/* No manual modification is permitted. */

#pragma once

  
// gamesvrdͳ�ƽṹ
class CGameStatMng : public singleton<CGameStatMng>
{
public:
	// gamesvrdͳ�ƽṹ
    CGameStatMng()
	{
		Clear();
	}
	// gamesvrdͳ�ƽṹ
    ~CGameStatMng()
	{
		Clear();
	}
		
	void SortArray(uint32_t * src, int srcSize, uint32_t * desId, uint32_t * desVal, int desSize, bool isMax)
	{
		if (isMax)
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t max = 0;
				for (int j = 0; j < srcSize; j++)
				{
					if (src[j] > max)
					{
						desId[i] = j;
						desVal[i] = src[j];
						max = src[j];
					}
				}
				src[desId[i]] = 0;
			}
		}
		else
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t min = 0xFFFFFFFF;
				for (int j = 0; j < srcSize; j++)
				{
					if (src[j] < min && src[j] > 0)
					{
						desId[i] = j;
						desVal[i] = src[j];
						min = src[j];
					}
				}
				src[desId[i]] = 0xFFFFFFFF;
			}
		}
	}

	template <typename Map>
	void SortHashMap(Map & map, uint32_t * desId, uint32_t * desVal, int desSize, bool isMax)
	{
		if (isMax)
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t max = 0;
				for (typename Map::iterator it = map.begin(); it != map.end(); it++)
				{
					if (it->second > max)
					{
						desId[i] = it->first;
						desVal[i] = it->second;
						max = it->second;
					}
				}
				typename Map::iterator it = map.find(desId[i]);
				if (it != map.end())
				{
					it->second = 0;
				}
			}
		}
		else
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t min = 0xFFFFFFFF;
				for (typename Map::iterator it = map.begin(); it != map.end(); it++)
				{
					if (it->second < min && it->second > 0)
					{
						desId[i] = it->first;
						desVal[i] = it->second;
						min = it->second;
					}
				}
				typename Map::iterator it = map.find(desId[i]);
				if (it != map.end())
				{
					it->second = 0xFFFFFFFF;
				}
			}
		}
	}
		
// ��������
public:
    int PrintLog(const char * strFile)
	{
		FILE *pLog = NULL;
		if ((pLog = fopen(strFile, "a+")) == NULL)
		{
			LOG_ERROR("open %s fail", strFile);
			return -2;
		}
		
		
		// client�� Top�հ���Ŀ
		uint32_t uTopCLRecvPacketNumId[5] = {0};
		uint32_t uTopCLRecvPacketNumVal[5] = {0};
		SortArray(m_TopCLRecvPacketNum, 2000, uTopCLRecvPacketNumId, uTopCLRecvPacketNumVal, 5, true);
		
		// client�� Top������Ŀ
		uint32_t uTopCLSendPacketNumId[5] = {0};
		uint32_t uTopCLSendPacketNumVal[5] = {0};
		SortArray(m_TopCLSendPacketNum, 2000, uTopCLSendPacketNumId, uTopCLSendPacketNumVal, 5, true);
		
		// client�� Top�հ�����
		uint32_t uTopCLRecvSizeNumId[5] = {0};
		uint32_t uTopCLRecvSizeNumVal[5] = {0};
		SortArray(m_TopCLRecvSizeNum, 2000, uTopCLRecvSizeNumId, uTopCLRecvSizeNumVal, 5, true);
		
		// client�� Top��������
		uint32_t uTopCLSendSizeNumId[5] = {0};
		uint32_t uTopCLSendSizeNumVal[5] = {0};
		SortArray(m_TopCLSendSizeNum, 2000, uTopCLSendSizeNumId, uTopCLSendSizeNumVal, 5, true);
		
		// client�� Top�հ�����ʱ��
		uint32_t uTopCLProcessTimeId[5] = {0};
		uint32_t uTopCLProcessTimeVal[5] = {0};
		SortArray(m_TopCLProcessTime, 2000, uTopCLProcessTimeId, uTopCLProcessTimeVal, 5, true);
		
		
		// Top��������
		uint32_t uTopSceneNumId[5] = {0};
		uint32_t uTopSceneNumVal[5] = {0};
		SortHashMap< fhashmap<uint32_t, uint32_t, 100> >(m_TopSceneNum, uTopSceneNumId, uTopSceneNumVal, 5, true);
		
		// Top��������
		uint32_t uTopDungeonNumId[5] = {0};
		uint32_t uTopDungeonNumVal[5] = {0};
		SortHashMap< fhashmap<uint32_t, uint32_t, 100> >(m_TopDungeonNum, uTopDungeonNumId, uTopDungeonNumVal, 5, true);
		
		
		fprintf(pLog, "=============================%s=============================\n"
			
			// ϵͳ����
			"LoadAvg\t%u\tϵͳ����\n"
			
			// cpuռ��
			"CPU\t%u\tcpuռ��\n"
			
			// ��ǰ���̵�cpuռ��
			"CurCPU\t%u\t��ǰ���̵�cpuռ��\n"
			
			// �����ڴ�ռ��
			"RES\t%u\t�����ڴ�ռ��\n"
			
			// �����ڴ�ռ��
			"VIRT\t%u\t�����ڴ�ռ��\n"
			
			// ֡��
			"FPS\t%u\t֡��\n"
			
			// ��С�㲥
			"MinBroadcast\t%u\t��С�㲥\n"
			
			// ���㲥
			"MaxBroadcast\t%u\t���㲥\n"
			
			
			
			// pvp���� ��״̬��Ŀ 0
			"PvPRoomStateNum0\t%u\tpvp���� ��״̬��Ŀ0\n"
			
			// pvp���� ��״̬��Ŀ 1
			"PvPRoomStateNum1\t%u\tpvp���� ��״̬��Ŀ1\n"
			
			// pvp���� ��״̬��Ŀ 2
			"PvPRoomStateNum2\t%u\tpvp���� ��״̬��Ŀ2\n"
			
			// pvp���� ��״̬��Ŀ 3
			"PvPRoomStateNum3\t%u\tpvp���� ��״̬��Ŀ3\n"
			
			// pvp���� ��״̬��Ŀ 4
			"PvPRoomStateNum4\t%u\tpvp���� ��״̬��Ŀ4\n"
			
			// pvp���� ��״̬��Ŀ 5
			"PvPRoomStateNum5\t%u\tpvp���� ��״̬��Ŀ5\n"
			
			// pvp���� ��״̬��Ŀ 6
			"PvPRoomStateNum6\t%u\tpvp���� ��״̬��Ŀ6\n"
			
			
			
			// pvp���� ��״̬����ʱ�� 0
			"PvPRoomStateTime0\t%u\tpvp���� ��״̬����ʱ��0\n"
			
			// pvp���� ��״̬����ʱ�� 1
			"PvPRoomStateTime1\t%u\tpvp���� ��״̬����ʱ��1\n"
			
			// pvp���� ��״̬����ʱ�� 2
			"PvPRoomStateTime2\t%u\tpvp���� ��״̬����ʱ��2\n"
			
			// pvp���� ��״̬����ʱ�� 3
			"PvPRoomStateTime3\t%u\tpvp���� ��״̬����ʱ��3\n"
			
			// pvp���� ��״̬����ʱ�� 4
			"PvPRoomStateTime4\t%u\tpvp���� ��״̬����ʱ��4\n"
			
			// pvp���� ��״̬����ʱ�� 5
			"PvPRoomStateTime5\t%u\tpvp���� ��״̬����ʱ��5\n"
			
			// pvp���� ��״̬����ʱ�� 6
			"PvPRoomStateTime6\t%u\tpvp���� ��״̬����ʱ��6\n"
			
			
			
			
			// client�� Top�հ���Ŀ 0
			"TopCLRecvPacketNumId0\t%u\tclient�� Top�հ���ĿId0\nTopCLRecvPacketNumVal0\t%u\tclient�� Top�հ���ĿVal0\n"
			
			// client�� Top�հ���Ŀ 1
			"TopCLRecvPacketNumId1\t%u\tclient�� Top�հ���ĿId1\nTopCLRecvPacketNumVal1\t%u\tclient�� Top�հ���ĿVal1\n"
			
			// client�� Top�հ���Ŀ 2
			"TopCLRecvPacketNumId2\t%u\tclient�� Top�հ���ĿId2\nTopCLRecvPacketNumVal2\t%u\tclient�� Top�հ���ĿVal2\n"
			
			// client�� Top�հ���Ŀ 3
			"TopCLRecvPacketNumId3\t%u\tclient�� Top�հ���ĿId3\nTopCLRecvPacketNumVal3\t%u\tclient�� Top�հ���ĿVal3\n"
			
			// client�� Top�հ���Ŀ 4
			"TopCLRecvPacketNumId4\t%u\tclient�� Top�հ���ĿId4\nTopCLRecvPacketNumVal4\t%u\tclient�� Top�հ���ĿVal4\n"
			
			
			
			// client�� Top������Ŀ 0
			"TopCLSendPacketNumId0\t%u\tclient�� Top������ĿId0\nTopCLSendPacketNumVal0\t%u\tclient�� Top������ĿVal0\n"
			
			// client�� Top������Ŀ 1
			"TopCLSendPacketNumId1\t%u\tclient�� Top������ĿId1\nTopCLSendPacketNumVal1\t%u\tclient�� Top������ĿVal1\n"
			
			// client�� Top������Ŀ 2
			"TopCLSendPacketNumId2\t%u\tclient�� Top������ĿId2\nTopCLSendPacketNumVal2\t%u\tclient�� Top������ĿVal2\n"
			
			// client�� Top������Ŀ 3
			"TopCLSendPacketNumId3\t%u\tclient�� Top������ĿId3\nTopCLSendPacketNumVal3\t%u\tclient�� Top������ĿVal3\n"
			
			// client�� Top������Ŀ 4
			"TopCLSendPacketNumId4\t%u\tclient�� Top������ĿId4\nTopCLSendPacketNumVal4\t%u\tclient�� Top������ĿVal4\n"
			
			
			
			// client�� Top�հ����� 0
			"TopCLRecvSizeNumId0\t%u\tclient�� Top�հ�����Id0\nTopCLRecvSizeNumVal0\t%u\tclient�� Top�հ�����Val0\n"
			
			// client�� Top�հ����� 1
			"TopCLRecvSizeNumId1\t%u\tclient�� Top�հ�����Id1\nTopCLRecvSizeNumVal1\t%u\tclient�� Top�հ�����Val1\n"
			
			// client�� Top�հ����� 2
			"TopCLRecvSizeNumId2\t%u\tclient�� Top�հ�����Id2\nTopCLRecvSizeNumVal2\t%u\tclient�� Top�հ�����Val2\n"
			
			// client�� Top�հ����� 3
			"TopCLRecvSizeNumId3\t%u\tclient�� Top�հ�����Id3\nTopCLRecvSizeNumVal3\t%u\tclient�� Top�հ�����Val3\n"
			
			// client�� Top�հ����� 4
			"TopCLRecvSizeNumId4\t%u\tclient�� Top�հ�����Id4\nTopCLRecvSizeNumVal4\t%u\tclient�� Top�հ�����Val4\n"
			
			
			
			// client�� Top�������� 0
			"TopCLSendSizeNumId0\t%u\tclient�� Top��������Id0\nTopCLSendSizeNumVal0\t%u\tclient�� Top��������Val0\n"
			
			// client�� Top�������� 1
			"TopCLSendSizeNumId1\t%u\tclient�� Top��������Id1\nTopCLSendSizeNumVal1\t%u\tclient�� Top��������Val1\n"
			
			// client�� Top�������� 2
			"TopCLSendSizeNumId2\t%u\tclient�� Top��������Id2\nTopCLSendSizeNumVal2\t%u\tclient�� Top��������Val2\n"
			
			// client�� Top�������� 3
			"TopCLSendSizeNumId3\t%u\tclient�� Top��������Id3\nTopCLSendSizeNumVal3\t%u\tclient�� Top��������Val3\n"
			
			// client�� Top�������� 4
			"TopCLSendSizeNumId4\t%u\tclient�� Top��������Id4\nTopCLSendSizeNumVal4\t%u\tclient�� Top��������Val4\n"
			
			
			
			// client�� Top�հ�����ʱ�� 0
			"TopCLProcessTimeId0\t%u\tclient�� Top�հ�����ʱ��Id0\nTopCLProcessTimeVal0\t%u\tclient�� Top�հ�����ʱ��Val0\n"
			
			// client�� Top�հ�����ʱ�� 1
			"TopCLProcessTimeId1\t%u\tclient�� Top�հ�����ʱ��Id1\nTopCLProcessTimeVal1\t%u\tclient�� Top�հ�����ʱ��Val1\n"
			
			// client�� Top�հ�����ʱ�� 2
			"TopCLProcessTimeId2\t%u\tclient�� Top�հ�����ʱ��Id2\nTopCLProcessTimeVal2\t%u\tclient�� Top�հ�����ʱ��Val2\n"
			
			// client�� Top�հ�����ʱ�� 3
			"TopCLProcessTimeId3\t%u\tclient�� Top�հ�����ʱ��Id3\nTopCLProcessTimeVal3\t%u\tclient�� Top�հ�����ʱ��Val3\n"
			
			// client�� Top�հ�����ʱ�� 4
			"TopCLProcessTimeId4\t%u\tclient�� Top�հ�����ʱ��Id4\nTopCLProcessTimeVal4\t%u\tclient�� Top�հ�����ʱ��Val4\n"
			
			
			
			
			// Top�������� 0
			"TopSceneNumId0\t%u\tTop��������Id0\nTopSceneNumVal0\t%u\tTop��������Val0\n"
			
			// Top�������� 1
			"TopSceneNumId1\t%u\tTop��������Id1\nTopSceneNumVal1\t%u\tTop��������Val1\n"
			
			// Top�������� 2
			"TopSceneNumId2\t%u\tTop��������Id2\nTopSceneNumVal2\t%u\tTop��������Val2\n"
			
			// Top�������� 3
			"TopSceneNumId3\t%u\tTop��������Id3\nTopSceneNumVal3\t%u\tTop��������Val3\n"
			
			// Top�������� 4
			"TopSceneNumId4\t%u\tTop��������Id4\nTopSceneNumVal4\t%u\tTop��������Val4\n"
			
			
			
			// Top�������� 0
			"TopDungeonNumId0\t%u\tTop��������Id0\nTopDungeonNumVal0\t%u\tTop��������Val0\n"
			
			// Top�������� 1
			"TopDungeonNumId1\t%u\tTop��������Id1\nTopDungeonNumVal1\t%u\tTop��������Val1\n"
			
			// Top�������� 2
			"TopDungeonNumId2\t%u\tTop��������Id2\nTopDungeonNumVal2\t%u\tTop��������Val2\n"
			
			// Top�������� 3
			"TopDungeonNumId3\t%u\tTop��������Id3\nTopDungeonNumVal3\t%u\tTop��������Val3\n"
			
			// Top�������� 4
			"TopDungeonNumId4\t%u\tTop��������Id4\nTopDungeonNumVal4\t%u\tTop��������Val4\n"
			
			
			"\n"
			
			, (const char *)fclock::ptr()->nowstr()
			
			// ϵͳ����
			, m_LoadAvg
			
			// cpuռ��
			, m_CPU
			
			// ��ǰ���̵�cpuռ��
			, m_CurCPU
			
			// �����ڴ�ռ��
			, m_RES
			
			// �����ڴ�ռ��
			, m_VIRT
			
			// ֡��
			, m_FPS
			
			// ��С�㲥
			, m_MinBroadcast
			
			// ���㲥
			, m_MaxBroadcast
			
			
			
			// pvp���� ��״̬��Ŀ 0
			, m_PvPRoomStateNum[0]
			
			// pvp���� ��״̬��Ŀ 1
			, m_PvPRoomStateNum[1]
			
			// pvp���� ��״̬��Ŀ 2
			, m_PvPRoomStateNum[2]
			
			// pvp���� ��״̬��Ŀ 3
			, m_PvPRoomStateNum[3]
			
			// pvp���� ��״̬��Ŀ 4
			, m_PvPRoomStateNum[4]
			
			// pvp���� ��״̬��Ŀ 5
			, m_PvPRoomStateNum[5]
			
			// pvp���� ��״̬��Ŀ 6
			, m_PvPRoomStateNum[6]
			
			
			
			// pvp���� ��״̬����ʱ�� 0
			, m_PvPRoomStateTime[0]
			
			// pvp���� ��״̬����ʱ�� 1
			, m_PvPRoomStateTime[1]
			
			// pvp���� ��״̬����ʱ�� 2
			, m_PvPRoomStateTime[2]
			
			// pvp���� ��״̬����ʱ�� 3
			, m_PvPRoomStateTime[3]
			
			// pvp���� ��״̬����ʱ�� 4
			, m_PvPRoomStateTime[4]
			
			// pvp���� ��״̬����ʱ�� 5
			, m_PvPRoomStateTime[5]
			
			// pvp���� ��״̬����ʱ�� 6
			, m_PvPRoomStateTime[6]
			
			
			
			
			// client�� Top�հ���Ŀ 0
			, uTopCLRecvPacketNumId[0], uTopCLRecvPacketNumVal[0]
			
			// client�� Top�հ���Ŀ 1
			, uTopCLRecvPacketNumId[1], uTopCLRecvPacketNumVal[1]
			
			// client�� Top�հ���Ŀ 2
			, uTopCLRecvPacketNumId[2], uTopCLRecvPacketNumVal[2]
			
			// client�� Top�հ���Ŀ 3
			, uTopCLRecvPacketNumId[3], uTopCLRecvPacketNumVal[3]
			
			// client�� Top�հ���Ŀ 4
			, uTopCLRecvPacketNumId[4], uTopCLRecvPacketNumVal[4]
			
			
			
			// client�� Top������Ŀ 0
			, uTopCLSendPacketNumId[0], uTopCLSendPacketNumVal[0]
			
			// client�� Top������Ŀ 1
			, uTopCLSendPacketNumId[1], uTopCLSendPacketNumVal[1]
			
			// client�� Top������Ŀ 2
			, uTopCLSendPacketNumId[2], uTopCLSendPacketNumVal[2]
			
			// client�� Top������Ŀ 3
			, uTopCLSendPacketNumId[3], uTopCLSendPacketNumVal[3]
			
			// client�� Top������Ŀ 4
			, uTopCLSendPacketNumId[4], uTopCLSendPacketNumVal[4]
			
			
			
			// client�� Top�հ����� 0
			, uTopCLRecvSizeNumId[0], uTopCLRecvSizeNumVal[0]
			
			// client�� Top�հ����� 1
			, uTopCLRecvSizeNumId[1], uTopCLRecvSizeNumVal[1]
			
			// client�� Top�հ����� 2
			, uTopCLRecvSizeNumId[2], uTopCLRecvSizeNumVal[2]
			
			// client�� Top�հ����� 3
			, uTopCLRecvSizeNumId[3], uTopCLRecvSizeNumVal[3]
			
			// client�� Top�հ����� 4
			, uTopCLRecvSizeNumId[4], uTopCLRecvSizeNumVal[4]
			
			
			
			// client�� Top�������� 0
			, uTopCLSendSizeNumId[0], uTopCLSendSizeNumVal[0]
			
			// client�� Top�������� 1
			, uTopCLSendSizeNumId[1], uTopCLSendSizeNumVal[1]
			
			// client�� Top�������� 2
			, uTopCLSendSizeNumId[2], uTopCLSendSizeNumVal[2]
			
			// client�� Top�������� 3
			, uTopCLSendSizeNumId[3], uTopCLSendSizeNumVal[3]
			
			// client�� Top�������� 4
			, uTopCLSendSizeNumId[4], uTopCLSendSizeNumVal[4]
			
			
			
			// client�� Top�հ�����ʱ�� 0
			, uTopCLProcessTimeId[0], uTopCLProcessTimeVal[0]
			
			// client�� Top�հ�����ʱ�� 1
			, uTopCLProcessTimeId[1], uTopCLProcessTimeVal[1]
			
			// client�� Top�հ�����ʱ�� 2
			, uTopCLProcessTimeId[2], uTopCLProcessTimeVal[2]
			
			// client�� Top�հ�����ʱ�� 3
			, uTopCLProcessTimeId[3], uTopCLProcessTimeVal[3]
			
			// client�� Top�հ�����ʱ�� 4
			, uTopCLProcessTimeId[4], uTopCLProcessTimeVal[4]
			
			
			
			
			// Top�������� 0
			, uTopSceneNumId[0], uTopSceneNumVal[0]
			
			// Top�������� 1
			, uTopSceneNumId[1], uTopSceneNumVal[1]
			
			// Top�������� 2
			, uTopSceneNumId[2], uTopSceneNumVal[2]
			
			// Top�������� 3
			, uTopSceneNumId[3], uTopSceneNumVal[3]
			
			// Top�������� 4
			, uTopSceneNumId[4], uTopSceneNumVal[4]
			
			
			
			// Top�������� 0
			, uTopDungeonNumId[0], uTopDungeonNumVal[0]
			
			// Top�������� 1
			, uTopDungeonNumId[1], uTopDungeonNumVal[1]
			
			// Top�������� 2
			, uTopDungeonNumId[2], uTopDungeonNumVal[2]
			
			// Top�������� 3
			, uTopDungeonNumId[3], uTopDungeonNumVal[3]
			
			// Top�������� 4
			, uTopDungeonNumId[4], uTopDungeonNumVal[4]
			
			
			);
			
		fclose(pLog);
		
		Clear();

		return 0;
	}
    
// ���Բ�������
public:
    
    // Get ϵͳ����
    uint32_t & GetLoadAvg()
    {
        return m_LoadAvg;
    }
    
    // Set ϵͳ����
    void SetLoadAvg(uint32_t _LoadAvg)
    {
        m_LoadAvg = _LoadAvg;
    }
    
    // Add ϵͳ����
    void AddLoadAvg(uint32_t _LoadAvg = 1)
    {
        m_LoadAvg += _LoadAvg;
    }
    
    // Get cpuռ��
    uint32_t & GetCPU()
    {
        return m_CPU;
    }
    
    // Set cpuռ��
    void SetCPU(uint32_t _CPU)
    {
        m_CPU = _CPU;
    }
    
    // Add cpuռ��
    void AddCPU(uint32_t _CPU = 1)
    {
        m_CPU += _CPU;
    }
    
    // Get ��ǰ���̵�cpuռ��
    uint32_t & GetCurCPU()
    {
        return m_CurCPU;
    }
    
    // Set ��ǰ���̵�cpuռ��
    void SetCurCPU(uint32_t _CurCPU)
    {
        m_CurCPU = _CurCPU;
    }
    
    // Add ��ǰ���̵�cpuռ��
    void AddCurCPU(uint32_t _CurCPU = 1)
    {
        m_CurCPU += _CurCPU;
    }
    
    // Get �����ڴ�ռ��
    uint32_t & GetRES()
    {
        return m_RES;
    }
    
    // Set �����ڴ�ռ��
    void SetRES(uint32_t _RES)
    {
        m_RES = _RES;
    }
    
    // Add �����ڴ�ռ��
    void AddRES(uint32_t _RES = 1)
    {
        m_RES += _RES;
    }
    
    // Get �����ڴ�ռ��
    uint32_t & GetVIRT()
    {
        return m_VIRT;
    }
    
    // Set �����ڴ�ռ��
    void SetVIRT(uint32_t _VIRT)
    {
        m_VIRT = _VIRT;
    }
    
    // Add �����ڴ�ռ��
    void AddVIRT(uint32_t _VIRT = 1)
    {
        m_VIRT += _VIRT;
    }
    
    // Get ֡��
    uint32_t & GetFPS()
    {
        return m_FPS;
    }
    
    // Set ֡��
    void SetFPS(uint32_t _FPS)
    {
        m_FPS = _FPS;
    }
    
    // Add ֡��
    void AddFPS(uint32_t _FPS = 1)
    {
        m_FPS += _FPS;
    }
    
    // Get ��С�㲥
    uint32_t & GetMinBroadcast()
    {
        return m_MinBroadcast;
    }
    
    // Set ��С�㲥
    void SetMinBroadcast(uint32_t _MinBroadcast)
    {
        m_MinBroadcast = _MinBroadcast < m_MinBroadcast ? _MinBroadcast : m_MinBroadcast;
    }
    
    
    
    // Get ���㲥
    uint32_t & GetMaxBroadcast()
    {
        return m_MaxBroadcast;
    }
    
    // Set ���㲥
    void SetMaxBroadcast(uint32_t _MaxBroadcast)
    {
        m_MaxBroadcast = _MaxBroadcast > m_MaxBroadcast ? _MaxBroadcast : m_MaxBroadcast;
    }
    
    
    
    
         
	// Set pvp���� ��״̬��Ŀ
    void SetPvPRoomStateNum(uint32_t index, uint32_t _PvPRoomStateNum)
    {
		if (index >= 7)
        {
            return;
        }
        m_PvPRoomStateNum[index] += _PvPRoomStateNum;
    }
	
    // Add pvp���� ��״̬��Ŀ
    void AddPvPRoomStateNum(uint32_t index, uint32_t _PvPRoomStateNum = 1)
    {
        if (index >= 7)
        {
            return;
        }
        m_PvPRoomStateNum[index] += _PvPRoomStateNum;
    }
         
	// Set pvp���� ��״̬����ʱ��
    void SetPvPRoomStateTime(uint32_t index, uint32_t _PvPRoomStateTime)
    {
		if (index >= 7)
        {
            return;
        }
        m_PvPRoomStateTime[index] += _PvPRoomStateTime;
    }
	
    // Add pvp���� ��״̬����ʱ��
    void AddPvPRoomStateTime(uint32_t index, uint32_t _PvPRoomStateTime = 1)
    {
        if (index >= 7)
        {
            return;
        }
        m_PvPRoomStateTime[index] += _PvPRoomStateTime;
    }
    
	
          
	// Set client�� Top�հ���Ŀ
    void SetTopCLRecvPacketNum(uint32_t index, uint32_t _TopCLRecvPacketNum)
    {
		if (index >= 2000)
        {
            return;
        }
        m_TopCLRecvPacketNum[index] += _TopCLRecvPacketNum;
    }
	       
    // Add client�� Top�հ���Ŀ
    void AddTopCLRecvPacketNum(uint32_t index, uint32_t _TopCLRecvPacketNum = 1)
    {
        if (index >= 2000)
        {
            return;
        }
        m_TopCLRecvPacketNum[index] += _TopCLRecvPacketNum;
    }
          
	// Set client�� Top������Ŀ
    void SetTopCLSendPacketNum(uint32_t index, uint32_t _TopCLSendPacketNum)
    {
		if (index >= 2000)
        {
            return;
        }
        m_TopCLSendPacketNum[index] += _TopCLSendPacketNum;
    }
	       
    // Add client�� Top������Ŀ
    void AddTopCLSendPacketNum(uint32_t index, uint32_t _TopCLSendPacketNum = 1)
    {
        if (index >= 2000)
        {
            return;
        }
        m_TopCLSendPacketNum[index] += _TopCLSendPacketNum;
    }
          
	// Set client�� Top�հ�����
    void SetTopCLRecvSizeNum(uint32_t index, uint32_t _TopCLRecvSizeNum)
    {
		if (index >= 2000)
        {
            return;
        }
        m_TopCLRecvSizeNum[index] += _TopCLRecvSizeNum;
    }
	       
    // Add client�� Top�հ�����
    void AddTopCLRecvSizeNum(uint32_t index, uint32_t _TopCLRecvSizeNum = 1)
    {
        if (index >= 2000)
        {
            return;
        }
        m_TopCLRecvSizeNum[index] += _TopCLRecvSizeNum;
    }
          
	// Set client�� Top��������
    void SetTopCLSendSizeNum(uint32_t index, uint32_t _TopCLSendSizeNum)
    {
		if (index >= 2000)
        {
            return;
        }
        m_TopCLSendSizeNum[index] += _TopCLSendSizeNum;
    }
	       
    // Add client�� Top��������
    void AddTopCLSendSizeNum(uint32_t index, uint32_t _TopCLSendSizeNum = 1)
    {
        if (index >= 2000)
        {
            return;
        }
        m_TopCLSendSizeNum[index] += _TopCLSendSizeNum;
    }
          
	// Set client�� Top�հ�����ʱ��
    void SetTopCLProcessTime(uint32_t index, uint32_t _TopCLProcessTime)
    {
		if (index >= 2000)
        {
            return;
        }
        m_TopCLProcessTime[index] += _TopCLProcessTime;
    }
	       
    // Add client�� Top�հ�����ʱ��
    void AddTopCLProcessTime(uint32_t index, uint32_t _TopCLProcessTime = 1)
    {
        if (index >= 2000)
        {
            return;
        }
        m_TopCLProcessTime[index] += _TopCLProcessTime;
    }
    
	
         
	// Set Top��������
    void SetTopSceneNum(uint32_t index, uint32_t _TopSceneNum)
    {
		fhashmap<uint32_t, uint32_t, 100>::iterator it = m_TopSceneNum.find(index);
        if (it == m_TopSceneNum.end())
        {
            m_TopSceneNum.insert(index, _TopSceneNum);
        }
        else
        {
            uint32_t & val = it->second;
            val = _TopSceneNum;
        }
    }
	        
    // Add Top��������
    void AddTopSceneNum(uint32_t index, uint32_t _TopSceneNum = 1)
    {
        fhashmap<uint32_t, uint32_t, 100>::iterator it = m_TopSceneNum.find(index);
        if (it == m_TopSceneNum.end())
        {
            m_TopSceneNum.insert(index, _TopSceneNum);
        }
        else
        {
            uint32_t & val = it->second;
            val += _TopSceneNum;
        }
    }
         
	// Set Top��������
    void SetTopDungeonNum(uint32_t index, uint32_t _TopDungeonNum)
    {
		fhashmap<uint32_t, uint32_t, 100>::iterator it = m_TopDungeonNum.find(index);
        if (it == m_TopDungeonNum.end())
        {
            m_TopDungeonNum.insert(index, _TopDungeonNum);
        }
        else
        {
            uint32_t & val = it->second;
            val = _TopDungeonNum;
        }
    }
	        
    // Add Top��������
    void AddTopDungeonNum(uint32_t index, uint32_t _TopDungeonNum = 1)
    {
        fhashmap<uint32_t, uint32_t, 100>::iterator it = m_TopDungeonNum.find(index);
        if (it == m_TopDungeonNum.end())
        {
            m_TopDungeonNum.insert(index, _TopDungeonNum);
        }
        else
        {
            uint32_t & val = it->second;
            val += _TopDungeonNum;
        }
    }
    
    
// �ڲ�����
private:
    void Clear()
	{
		
		// ϵͳ����
		m_LoadAvg = 0;
		
		// cpuռ��
		m_CPU = 0;
		
		// ��ǰ���̵�cpuռ��
		m_CurCPU = 0;
		
		// �����ڴ�ռ��
		m_RES = 0;
		
		// �����ڴ�ռ��
		m_VIRT = 0;
		
		// ֡��
		m_FPS = 0;
		
		// ��С�㲥
		m_MinBroadcast = 0;
		
		// ���㲥
		m_MaxBroadcast = 0;
		
		
		// pvp���� ��״̬��Ŀ
		memset(m_PvPRoomStateNum, 0, sizeof(m_PvPRoomStateNum));
		
		// pvp���� ��״̬����ʱ��
		memset(m_PvPRoomStateTime, 0, sizeof(m_PvPRoomStateTime));
		
		
		// client�� Top�հ���Ŀ
		memset(m_TopCLRecvPacketNum, 0, sizeof(m_TopCLRecvPacketNum));
		
		// client�� Top������Ŀ
		memset(m_TopCLSendPacketNum, 0, sizeof(m_TopCLSendPacketNum));
		
		// client�� Top�հ�����
		memset(m_TopCLRecvSizeNum, 0, sizeof(m_TopCLRecvSizeNum));
		
		// client�� Top��������
		memset(m_TopCLSendSizeNum, 0, sizeof(m_TopCLSendSizeNum));
		
		// client�� Top�հ�����ʱ��
		memset(m_TopCLProcessTime, 0, sizeof(m_TopCLProcessTime));
		
		
		// Top��������
		m_TopSceneNum.clear();
		
		// Top��������
		m_TopDungeonNum.clear();
		
	}

// ����
private:
    
    // ϵͳ����
    uint32_t m_LoadAvg;
    
    // cpuռ��
    uint32_t m_CPU;
    
    // ��ǰ���̵�cpuռ��
    uint32_t m_CurCPU;
    
    // �����ڴ�ռ��
    uint32_t m_RES;
    
    // �����ڴ�ռ��
    uint32_t m_VIRT;
    
    // ֡��
    uint32_t m_FPS;
    
    // ��С�㲥
    uint32_t m_MinBroadcast;
    
    // ���㲥
    uint32_t m_MaxBroadcast;
    
    
    // pvp���� ��״̬��Ŀ
    uint32_t m_PvPRoomStateNum[7];
    
    // pvp���� ��״̬����ʱ��
    uint32_t m_PvPRoomStateTime[7];
    
    
    // client�� Top�հ���Ŀ
    uint32_t m_TopCLRecvPacketNum[2000];
    
    // client�� Top������Ŀ
    uint32_t m_TopCLSendPacketNum[2000];
    
    // client�� Top�հ�����
    uint32_t m_TopCLRecvSizeNum[2000];
    
    // client�� Top��������
    uint32_t m_TopCLSendSizeNum[2000];
    
    // client�� Top�հ�����ʱ��
    uint32_t m_TopCLProcessTime[2000];
        
    
    // Top��������
    fhashmap<uint32_t, uint32_t, 100> m_TopSceneNum;
    
    // Top��������
    fhashmap<uint32_t, uint32_t, 100> m_TopDungeonNum;
        
};
  
// dbsvrdͳ�ƽṹ
class CDBStatMng : public singleton<CDBStatMng>
{
public:
	// dbsvrdͳ�ƽṹ
    CDBStatMng()
	{
		Clear();
	}
	// dbsvrdͳ�ƽṹ
    ~CDBStatMng()
	{
		Clear();
	}
		
	void SortArray(uint32_t * src, int srcSize, uint32_t * desId, uint32_t * desVal, int desSize, bool isMax)
	{
		if (isMax)
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t max = 0;
				for (int j = 0; j < srcSize; j++)
				{
					if (src[j] > max)
					{
						desId[i] = j;
						desVal[i] = src[j];
						max = src[j];
					}
				}
				src[desId[i]] = 0;
			}
		}
		else
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t min = 0xFFFFFFFF;
				for (int j = 0; j < srcSize; j++)
				{
					if (src[j] < min && src[j] > 0)
					{
						desId[i] = j;
						desVal[i] = src[j];
						min = src[j];
					}
				}
				src[desId[i]] = 0xFFFFFFFF;
			}
		}
	}

	template <typename Map>
	void SortHashMap(Map & map, uint32_t * desId, uint32_t * desVal, int desSize, bool isMax)
	{
		if (isMax)
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t max = 0;
				for (typename Map::iterator it = map.begin(); it != map.end(); it++)
				{
					if (it->second > max)
					{
						desId[i] = it->first;
						desVal[i] = it->second;
						max = it->second;
					}
				}
				typename Map::iterator it = map.find(desId[i]);
				if (it != map.end())
				{
					it->second = 0;
				}
			}
		}
		else
		{
			for (int i = 0; i < desSize; i++)
			{
				desId[i] = 0;
				desVal[i] = 0;
				uint32_t min = 0xFFFFFFFF;
				for (typename Map::iterator it = map.begin(); it != map.end(); it++)
				{
					if (it->second < min && it->second > 0)
					{
						desId[i] = it->first;
						desVal[i] = it->second;
						min = it->second;
					}
				}
				typename Map::iterator it = map.find(desId[i]);
				if (it != map.end())
				{
					it->second = 0xFFFFFFFF;
				}
			}
		}
	}
		
// ��������
public:
    int PrintLog(const char * strFile)
	{
		FILE *pLog = NULL;
		if ((pLog = fopen(strFile, "a+")) == NULL)
		{
			LOG_ERROR("open %s fail", strFile);
			return -2;
		}
		
		
		// Top DBExecutor֡��
		uint32_t uTopExecutorFPSId[5] = {0};
		uint32_t uTopExecutorFPSVal[5] = {0};
		SortArray(m_TopExecutorFPS, 100, uTopExecutorFPSId, uTopExecutorFPSVal, 5, false);
		
		
		
		fprintf(pLog, "=============================%s=============================\n"
			
			// ϵͳ����
			"LoadAvg\t%u\tϵͳ����\n"
			
			// cpuռ��
			"CPU\t%u\tcpuռ��\n"
			
			// ��ǰ���̵�cpuռ��
			"CurCPU\t%u\t��ǰ���̵�cpuռ��\n"
			
			// �����ڴ�ռ��
			"RES\t%u\t�����ڴ�ռ��\n"
			
			// �����ڴ�ռ��
			"VIRT\t%u\t�����ڴ�ռ��\n"
			
			// ֡��
			"FPS\t%u\t֡��\n"
			
			
			
			// ÿ��Handle֡�� 0
			"PerHandleFPS0\t%u\tÿ��Handle֡��0\n"
			
			// ÿ��Handle֡�� 1
			"PerHandleFPS1\t%u\tÿ��Handle֡��1\n"
			
			// ÿ��Handle֡�� 2
			"PerHandleFPS2\t%u\tÿ��Handle֡��2\n"
			
			// ÿ��Handle֡�� 3
			"PerHandleFPS3\t%u\tÿ��Handle֡��3\n"
			
			// ÿ��Handle֡�� 4
			"PerHandleFPS4\t%u\tÿ��Handle֡��4\n"
			
			// ÿ��Handle֡�� 5
			"PerHandleFPS5\t%u\tÿ��Handle֡��5\n"
			
			// ÿ��Handle֡�� 6
			"PerHandleFPS6\t%u\tÿ��Handle֡��6\n"
			
			// ÿ��Handle֡�� 7
			"PerHandleFPS7\t%u\tÿ��Handle֡��7\n"
			
			
			
			
			// Top DBExecutor֡�� 0
			"TopExecutorFPSId0\t%u\tTop DBExecutor֡��Id0\nTopExecutorFPSVal0\t%u\tTop DBExecutor֡��Val0\n"
			
			// Top DBExecutor֡�� 1
			"TopExecutorFPSId1\t%u\tTop DBExecutor֡��Id1\nTopExecutorFPSVal1\t%u\tTop DBExecutor֡��Val1\n"
			
			// Top DBExecutor֡�� 2
			"TopExecutorFPSId2\t%u\tTop DBExecutor֡��Id2\nTopExecutorFPSVal2\t%u\tTop DBExecutor֡��Val2\n"
			
			// Top DBExecutor֡�� 3
			"TopExecutorFPSId3\t%u\tTop DBExecutor֡��Id3\nTopExecutorFPSVal3\t%u\tTop DBExecutor֡��Val3\n"
			
			// Top DBExecutor֡�� 4
			"TopExecutorFPSId4\t%u\tTop DBExecutor֡��Id4\nTopExecutorFPSVal4\t%u\tTop DBExecutor֡��Val4\n"
			
			
			
			"\n"
			
			, (const char *)fclock::ptr()->nowstr()
			
			// ϵͳ����
			, m_LoadAvg
			
			// cpuռ��
			, m_CPU
			
			// ��ǰ���̵�cpuռ��
			, m_CurCPU
			
			// �����ڴ�ռ��
			, m_RES
			
			// �����ڴ�ռ��
			, m_VIRT
			
			// ֡��
			, m_FPS
			
			
			
			// ÿ��Handle֡�� 0
			, m_PerHandleFPS[0]
			
			// ÿ��Handle֡�� 1
			, m_PerHandleFPS[1]
			
			// ÿ��Handle֡�� 2
			, m_PerHandleFPS[2]
			
			// ÿ��Handle֡�� 3
			, m_PerHandleFPS[3]
			
			// ÿ��Handle֡�� 4
			, m_PerHandleFPS[4]
			
			// ÿ��Handle֡�� 5
			, m_PerHandleFPS[5]
			
			// ÿ��Handle֡�� 6
			, m_PerHandleFPS[6]
			
			// ÿ��Handle֡�� 7
			, m_PerHandleFPS[7]
			
			
			
			
			// Top DBExecutor֡�� 0
			, uTopExecutorFPSId[0], uTopExecutorFPSVal[0]
			
			// Top DBExecutor֡�� 1
			, uTopExecutorFPSId[1], uTopExecutorFPSVal[1]
			
			// Top DBExecutor֡�� 2
			, uTopExecutorFPSId[2], uTopExecutorFPSVal[2]
			
			// Top DBExecutor֡�� 3
			, uTopExecutorFPSId[3], uTopExecutorFPSVal[3]
			
			// Top DBExecutor֡�� 4
			, uTopExecutorFPSId[4], uTopExecutorFPSVal[4]
			
			
			
			);
			
		fclose(pLog);
		
		Clear();

		return 0;
	}
    
// ���Բ�������
public:
    
    // Get ϵͳ����
    uint32_t & GetLoadAvg()
    {
        return m_LoadAvg;
    }
    
    // Set ϵͳ����
    void SetLoadAvg(uint32_t _LoadAvg)
    {
        m_LoadAvg = _LoadAvg;
    }
    
    // Add ϵͳ����
    void AddLoadAvg(uint32_t _LoadAvg = 1)
    {
        m_LoadAvg += _LoadAvg;
    }
    
    // Get cpuռ��
    uint32_t & GetCPU()
    {
        return m_CPU;
    }
    
    // Set cpuռ��
    void SetCPU(uint32_t _CPU)
    {
        m_CPU = _CPU;
    }
    
    // Add cpuռ��
    void AddCPU(uint32_t _CPU = 1)
    {
        m_CPU += _CPU;
    }
    
    // Get ��ǰ���̵�cpuռ��
    uint32_t & GetCurCPU()
    {
        return m_CurCPU;
    }
    
    // Set ��ǰ���̵�cpuռ��
    void SetCurCPU(uint32_t _CurCPU)
    {
        m_CurCPU = _CurCPU;
    }
    
    // Add ��ǰ���̵�cpuռ��
    void AddCurCPU(uint32_t _CurCPU = 1)
    {
        m_CurCPU += _CurCPU;
    }
    
    // Get �����ڴ�ռ��
    uint32_t & GetRES()
    {
        return m_RES;
    }
    
    // Set �����ڴ�ռ��
    void SetRES(uint32_t _RES)
    {
        m_RES = _RES;
    }
    
    // Add �����ڴ�ռ��
    void AddRES(uint32_t _RES = 1)
    {
        m_RES += _RES;
    }
    
    // Get �����ڴ�ռ��
    uint32_t & GetVIRT()
    {
        return m_VIRT;
    }
    
    // Set �����ڴ�ռ��
    void SetVIRT(uint32_t _VIRT)
    {
        m_VIRT = _VIRT;
    }
    
    // Add �����ڴ�ռ��
    void AddVIRT(uint32_t _VIRT = 1)
    {
        m_VIRT += _VIRT;
    }
    
    // Get ֡��
    uint32_t & GetFPS()
    {
        return m_FPS;
    }
    
    // Set ֡��
    void SetFPS(uint32_t _FPS)
    {
        m_FPS = _FPS;
    }
    
    // Add ֡��
    void AddFPS(uint32_t _FPS = 1)
    {
        m_FPS += _FPS;
    }
    
    
         
	// Set ÿ��Handle֡��
    void SetPerHandleFPS(uint32_t index, uint32_t _PerHandleFPS)
    {
		if (index >= 8)
        {
            return;
        }
        m_PerHandleFPS[index] += _PerHandleFPS;
    }
	
    // Add ÿ��Handle֡��
    void AddPerHandleFPS(uint32_t index, uint32_t _PerHandleFPS = 1)
    {
        if (index >= 8)
        {
            return;
        }
        m_PerHandleFPS[index] += _PerHandleFPS;
    }
    
	
          
	// Set Top DBExecutor֡��
    void SetTopExecutorFPS(uint32_t index, uint32_t _TopExecutorFPS)
    {
		if (index >= 100)
        {
            return;
        }
        m_TopExecutorFPS[index] += _TopExecutorFPS;
    }
	       
    // Add Top DBExecutor֡��
    void AddTopExecutorFPS(uint32_t index, uint32_t _TopExecutorFPS = 1)
    {
        if (index >= 100)
        {
            return;
        }
        m_TopExecutorFPS[index] += _TopExecutorFPS;
    }
    
	
    
    
// �ڲ�����
private:
    void Clear()
	{
		
		// ϵͳ����
		m_LoadAvg = 0;
		
		// cpuռ��
		m_CPU = 0;
		
		// ��ǰ���̵�cpuռ��
		m_CurCPU = 0;
		
		// �����ڴ�ռ��
		m_RES = 0;
		
		// �����ڴ�ռ��
		m_VIRT = 0;
		
		// ֡��
		m_FPS = 0;
		
		
		// ÿ��Handle֡��
		memset(m_PerHandleFPS, 0, sizeof(m_PerHandleFPS));
		
		
		// Top DBExecutor֡��
		memset(m_TopExecutorFPS, 0, sizeof(m_TopExecutorFPS));
		
		
	}

// ����
private:
    
    // ϵͳ����
    uint32_t m_LoadAvg;
    
    // cpuռ��
    uint32_t m_CPU;
    
    // ��ǰ���̵�cpuռ��
    uint32_t m_CurCPU;
    
    // �����ڴ�ռ��
    uint32_t m_RES;
    
    // �����ڴ�ռ��
    uint32_t m_VIRT;
    
    // ֡��
    uint32_t m_FPS;
    
    
    // ÿ��Handle֡��
    uint32_t m_PerHandleFPS[8];
    
    
    // Top DBExecutor֡��
    uint32_t m_TopExecutorFPS[100];
        
        
};
