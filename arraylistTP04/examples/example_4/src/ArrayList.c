#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
    {
       returnAux =  0;
       if (this->size < this->reservedSize)
       {
           this->pElements[this->size] = pElement;//mucho  mas visible a simple vista
           //*(this->pElements)+(this->size) =  pElement;//este supone ser mucho  mas profesional
           this->size++;
       }
       /*if (this->size == this->reservedSize)
       {
           if(resizeUp(this) != 0)
           {

           }
       }*/

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        free(this);

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index)
{
    int* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= this->size)
    {
        returnAux = this->pElements[index];
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1, i ;

    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
             if(this->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
            else{
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL && index >=0 && index < this->size)
    {
        returnAux = 0;
        this->pElements[index] = pElement;

    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1, i;
    if(this!= NULL && index >= 0 && index < this->size)
    {
        returnAux = 0;
        for(i = 0; i < this->size; i++)
        {
            this->pElements[index] = this->pElements[index+1];//Preguntar  si  esto  esta bien
        }
        this->size--;
    }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        this-> size = 0;
        //falta reallocar para volver a tener el  tama�o  inicial
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    int i;
    ArrayList* returnAux;
    ArrayList* returnAux2 = NULL;
    returnAux = al_newArrayList();
    if(this != NULL)
    {
        for(i= 0; i < this->size; i++)
        {
            returnAux->size = this->size;
            returnAux->pElements = this->pElements;
            returnAux->reservedSize = this->reservedSize;
            returnAux->add = this->add;
            returnAux->clear = this->clear;
            returnAux->len = this->len;
            returnAux->set = this->set;
            returnAux->remove = this->remove;
            returnAux->clone = this->clone;
            returnAux->get = this->get;
            returnAux->contains = this->contains;
            returnAux->push = this->push;
            returnAux->indexOf = this->indexOf;
            returnAux->isEmpty = this->isEmpty;
            returnAux->pop = this->pop;
            returnAux->subList = this->subList;
            returnAux->containsAll = this->containsAll;
            returnAux->deleteArrayList = this->deleteArrayList;
            returnAux->sort = this->sort;
        }
        return returnAux2 = returnAux;

        //creo  el  new arraylist,  recorro  el  array  original  y  le voy  pasando  los datos del  original  al  nuevo

    }

    return returnAux2;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index<= this->size && pElement != NULL)
    {
        returnAux =  0;
        //resizeUP
        resizeUp(this);
        if(expand(this, index) == 0)
        {
            returnAux = 0;
            al_set(this, index, pElement);

            this->size++;
        }
        //for(i = this->size-1; i >= index; i--)
        //{
           // this->pElements[i+1] = this->pElements[i];
        //}

        //returnAux = 0;
        //this->size ++;

    }


    return returnAux;
}


/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1, i;
    if(this != NULL && pElement != NULL )
    {

        for( i = 0 ; i<this->size; i++)
        {
           /* this->pElements[this->size] = pElement;//mucho  mas visible a simple vista
           //*(this->pElements)+(this->size) =  pElement;//este supone ser mucho  mas profesional
           this->size++;*/

            if(this->pElements[i]== pElement)
            {
                returnAux = i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {
       returnAux = 0;
       if(al_len(this) == 0)
       {
           returnAux = 1;    ;
       }

    }
    return returnAux;
}

/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index <= this->size && index >=0)
    {
        //returnAux = al_get(this, index);
        returnAux = this->pElements[index];
        al_remove(this, index);

    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    int i;
    if(this != NULL && from >=0 && from < to  && to <=this->size)
    {
        returnAux = al_newArrayList();
        if(returnAux != NULL)
        {
          // for (i = this->pElements[from]; i < this->pElements[to]; i++ )
            for(i = from ; i<to; i++)
            {
                //returnAux = this->pElements[i];
                this->add(returnAux,this->get(this, i));
                //al_add(returnAux,this->pElements+i);


            }
        }

    }

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* pList2)
{
    int returnAux = -1, i;
    if(this != NULL && pList2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i<this->size; i++)
        {
            //if(this->pElements[i] == pList2->pElements[i])
            if(al_contains(this, pList2->pElements[i])==0)
            {
                returnAux = 0;
            }

        }

    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1, i;
    void* aux;
    int  flag =  1;
    //int len = al_len()

    if(this != NULL && pFunc != NULL && (order ==1 || order ==0))
    {
        returnAux = 0;
        while(flag)
        {
            flag = 0;
            for (i = 1; i < this->size; i++)
            {
                if (order == 1)
                {
                    if(pFunc(this->pElements[i], this->pElements[i-1]) < 0)
                    {
                        aux = this->pElements[i];
                        this->pElements[i] = this->pElements[i-1];
                        this->pElements[i-1] = aux;
                        flag = 1;
                    }

                }
                else

                {
                    if(order == 0)
                    {
                        if(pFunc(this->pElements[i], this->pElements[i-1]) > 0)
                        {
                            aux = this->pElements[i];
                            this->pElements[i] = this->pElements[i-1];
                            this->pElements[i-1] = aux;
                            flag = 1;
                        }

                    }

                }
            }
        }


    }


    return returnAux;
}



/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void* auxpElements;
    if(this != NULL && this->reservedSize == this->size)
    {
        auxpElements = (void *)realloc(this->pElements,sizeof(void *) * (this->reservedSize + AL_INCREMENT));
        if(auxpElements != NULL)
        {
            this->pElements = auxpElements;
            this->reservedSize = this->reservedSize +AL_INCREMENT;
            returnAux = 0;
        }

    }

    return returnAux;

}
/*int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void* aux;

    if(this != NULL)
    {
        returnAux = 0;  // bandera
        if(this->size == this->reservedSize)
        {
            returnAux = -1; // bandera

            aux=(void*)realloc(this->pElements,sizeof(void*)*(this->size + AL_INCREMENT));

            if(aux != NULL)
            {
                //printf("test");
                this->pElements = aux;
                this->reservedSize = (this->size + AL_INCREMENT);
                returnAux = 0;
            }
        }
    }

    return returnAux;

}*/


/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
/*int expand(ArrayList* this,int index)
{
    int returnAux = -1, i;

    if(this != NULL && (index <= this->size && index >=0))
    {


        for(i = this->size-1; i >= index; i--)
        {
            this->pElements[i+1] = this->pElements[i];
        }
        returnAux = 0;
    }
    return returnAux;
}*/

int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    int i;

    if(this != NULL && index >= 0 && index <= al_len(this))
    {
        for(i = al_len(this)-1; i >= index; i--)
        {
            al_set(this,i,al_get(this,i-1));
        }

        this->size++;

        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;

    return returnAux;
}
