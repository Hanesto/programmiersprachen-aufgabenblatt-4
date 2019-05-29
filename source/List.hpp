#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode{
    T value = T ();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
    using Self = ListIterator<T>;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    /*Gibt den Wert des Elements zurück, auf dass der Iterator zeigt*/
    T& operator*() const
    {
      return node->value;
    }

    T& operator->() const;

    ListIterator<T>& operator++()
    {
      return next();
    }

    ListIterator<T> operator++(int x);
    bool operator==(ListIterator<T> const& x) const;
    bool operator!=(ListIterator<T> const& x) const;
    
    /* Gibt die next Node der Node des Iterators aus, falls vorhanden*/
    ListIterator<T> next() const
    {
        if(nullptr != node)
        {
            return ListIterator{node->next};
        }else{
            return ListIterator{nullptr};
        }
    }

    ListNode<T>* node = nullptr;
};

template <typename T>
class List{
    public:
     using value_type = T;
     using pointer = T*;
     using const_pointer = T const*;
     using reference = T&;
     using const_reference = T const&;
     using iterator = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
  	/* ... */
    List():size_{0}, first_{nullptr}, last_{nullptr} {}

    /* ... */
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* ... */
    //TODO: operator== (Aufgabe 4.7)

  	/* ... */
    //TODO: operator!= (Aufgabe 4.7)

  	/* Wird aufgerufen, sobald die Liste gelöscht wird (Destruktor) */
    ~List() {
  		clear();
    }

  	/* Gibt einen Zeiger auf das erste Element in der Liste zurück */
    ListIterator<T> begin() {
    	assert(!empty());
  	  ListIterator<T> itr;
      //weise dem Iterator die erste Node zu
      itr.node = first_;
      return itr;
    }

  	/* Gibt einen Zeiger auf das letzte Element in der Liste zurück */
    ListIterator<T> end() {
    	assert(!empty());
      ListIterator<T> itr;
      //weise dem Iterator die letzte Node hinzu
      itr.node = last_;
      return itr;
    }

    /* löscht alle Elemente aus der Liste */
    void clear() {
  		if(!empty())
      {
        while (size_ > 0)
        {
          pop_back();
        }      
      }
    }

    /* Fügt ein Element an einer bestimmten Position ein */
    //TODO: member function insert

  	/* Dreht den Inhalt der Liste um */
    //TODO: member function reverse

    /* Fügt vorne ein Element hinzu */
    void push_front(T const& element) {
  		if(!empty())
      {
        ListNode<T>* newNode = new ListNode<T>{element, nullptr, first_};
        first_->prev = newNode;
        first_ = newNode;
        size_++;
      }
      else
      {
        ListNode<T>* newNode = new ListNode<T>{element};
        first_ = newNode;
        last_ = newNode;
        size_++;
      }      
    }

    /* Fügt hinten ein Element hinzu */
    void push_back(T const& element) {	
    	if(!empty())
      {
        ListNode<T>* newNode = new ListNode<T>{element, last_, nullptr};
        last_ = newNode;
        size_++;
      }
      else
      {
        ListNode<T>* newNode = new ListNode<T>{element};

        first_ = newNode;
        last_ = newNode;
        size_++;
      }      
    }

    /* löscht ein Element von vorne aus der Liste */
    void pop_front() {
    	assert(!empty());
      if(size_ == 1)
      {
        first_ == nullptr;
        last_ == nullptr;
        size_--;
      }
      else
      {
        first_ = first_->next;
        first_->prev = nullptr;
        size_--;
      }
    }
  
    /* löscht ein Element von hinten aus der Liste */
    void pop_back() {
    	assert(!empty());
      if(size_ == 1)
      {
        first_ == nullptr;
        last_ == nullptr;
        size_--;
      }
      else
      {
        last_ = last_->prev;
        last_->next = nullptr;
        size_--;
      }
    }

  	/* Gibt das erste Element der Liste zurück*/
    T& front() {
    	assert(!empty());
  		return first_->value;
    }

  	/*  Gibt das letzte Element der Liste zurück*/
    T& back() {
    	assert(!empty());
      return last_->value;
    }

  	/* checkt, ob die Liste leer ist*/
    bool empty() const {
      if(size_ == 0)
      {
        return true;
      }
      else{return false;} 
      };

    /* Gibt die Anzahl an Elementen aus*/
  std::size_t size() {
    return size_;
  };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* Dreht die Liste um*/
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif