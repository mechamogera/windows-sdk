#pragma once

constexpr int KEYWORD_STRING_SIZE = 256;
constexpr int JSON_STRING_SIZE = 4096;

/// <summary>
/// System::Collections::Generic::ReadOnlyList����󂯎�������X�g���i�[����N���X
/// </summary>
template <typename T>
class ReadOnlyList
{
public:
	virtual ~ReadOnlyList() {};
	virtual T Get(int index) = 0;
	virtual int Count() const = 0;
};

/// <summary>
/// ReadOnlyList�N���X�̃C���X�^���X�𐶐�����֐�
/// </summary>
template <typename T>
ReadOnlyList<T>* CreateReadOnlyList(int count, T* items);

/// <summary>
/// System::Collections::Generic::List����󂯎�������X�g���i�[����N���X
/// </summary>
template <typename T>
class List : public ReadOnlyList<T>
{
public:
	virtual void Add(const T item) = 0;
	virtual void Remove(int index) = 0;
	virtual ~List() {};
};
/// <summary>
/// List�N���X�̃C���X�^���X�𐶐�����֐�
/// </summary>
template <typename T>
List<T>* CreateList();
/// <summary>
/// ReadOnlyList�̃C���X�^���X�𐶐�����֐�
/// �������ɒl���i�[����ۂɎg�p����
/// </summary>
template <typename T>
List<T>* CreateList(int count, T* items);

/// <summary>
/// System::Collections::Generic::Dictionary����󂯎�������X�g���i�[����N���X
/// </summary>
template <typename T>
class Dictionary
{
public:
	virtual void Add(const char* key, T value) = 0;
	virtual void Remove(const char* key) = 0;
	virtual T Get(const char* key) = 0;
	virtual bool Contains(const char* key) const = 0;
	virtual ReadOnlyList<const char*>* GetKeys() const = 0;

	virtual ~Dictionary() {};
};

/// <summary>
/// Dictionary�N���X�̃C���X�^���X�𐶐�����֐�
/// </summary>
template <typename T>
Dictionary<T>* CreateDictionary();

/// <summary>
/// System::Collections::Generic::List����󂯎�������X�g���i�[����N���X
/// �i�[����l��String�̍ۂɎg�p����
/// </summary>
class StringList : public List<const char*> 
{
};

/// <summary>
/// System::Collections::Generic::Dictionary����󂯎�������X�g���i�[����N���X
/// �i�[����L�[�ƒl�̑g�ݍ��킹��[String,object]�̍ۂɎg�p����
/// </summary>
class StringDictionary : public Dictionary<const char*> 
{
};
