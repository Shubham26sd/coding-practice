import React, { useState } from "react";
import { useSelector, useDispatch } from "react-redux";
import { removeTodo, updateTodo } from "../features/todo/todoSlice";

function Todos() {
  const todos = useSelector((state) => state.todos);
  const dispatch = useDispatch();

  const [input, setInput] = useState("");
  const [editId, setEditId] = useState(null);

  const handleEdit = (e) => {
    e.preventDefault();
    if (input && input.trim()) {
      dispatch(updateTodo({ id: editId, text: input }));
      setEditId(null);
      setInput("");
    }
  };

  return (
    <>
      <div className="flex justify-center items-center text-4xl text-white my-7 uppercase">
        Todos
      </div>
      <ul className="list-none">
        {todos.map((todo) => (
          <li
            className="m-6 rounded-3xl h-15 flex justify-between items-center bg-zinc-800 px-4 py-2 rounded"
            key={todo.id}
          >
            {editId == todo.id ? (
              <form className="w-full flex justify-between mx-4">
                <input
                  autoFocus
                  className="flex-grow p-1 rounded text-white "
                  onChange={(e) => setInput(e.target.value)}
                ></input>
                <button
                  type="submit"
                  className="ml-2 px-3 py-1 bg-green-600 text-white rounded hover:bg-green-700"
                  onClick={handleEdit}
                >
                  Submit
                </button>
              </form>
            ) : (
              <div className="text-white">{todo.text}</div>
            )}
            <div className="flex gap-3">
              <button
                onClick={() => {
                  setEditId(todo.id);
                }}
                className="text-white bg-blue-500 border-0 py-1 px-4 focus:outline-none hover:bg-blue-600 rounded text-md"
              >
                <svg
                  xmlns="http://www.w3.org/2000/svg"
                  fill="none"
                  viewBox="0 0 24 24"
                  strokeWidth={1.5}
                  stroke="currentColor"
                  className="w-6 h-6"
                >
                  <path
                    strokeLinecap="round"
                    strokeLinejoin="round"
                    d="M16.862 3.487a2.25 2.25 0 113.182 3.182L7.5 19.5 3 21l1.5-4.5 12.362-12.362z"
                  />
                </svg>
              </button>

              <button
                onClick={() => dispatch(removeTodo(todo.id))}
                className="text-white bg-red-500 border-0 py-1 px-4 focus:outline-none hover:bg-red-600 rounded text-md"
              >
                <svg
                  xmlns="http://www.w3.org/2000/svg"
                  fill="none"
                  viewBox="0 0 24 24"
                  strokeWidth={1.5}
                  stroke="currentColor"
                  className="w-6 h-6"
                >
                  <path
                    strokeLinecap="round"
                    strokeLinejoin="round"
                    d="M14.74 9l-.346 9m-4.788 0L9.26 9m9.968-3.21c.342.052.682.107 1.022.166m-1.022-.165L18.16 19.673a2.25 2.25 0 01-2.244 2.077H8.084a2.25 2.25 0 01-2.244-2.077L4.772 5.79m14.456 0a48.108 48.108 0 00-3.478-.397m-12 .562c.34-.059.68-.114 1.022-.165m0 0a48.11 48.11 0 013.478-.397m7.5 0v-.916c0-1.18-.91-2.164-2.09-2.201a51.964 51.964 0 00-3.32 0c-1.18.037-2.09 1.022-2.09 2.201v.916m7.5 0a48.667 48.667 0 00-7.5 0"
                  />
                </svg>
              </button>
            </div>
          </li>
        ))}
      </ul>
    </>
  );
}

export default Todos;
